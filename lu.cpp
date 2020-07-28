#include <iostream>
#include <algorithm>
#include <mpi.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_permutation.h>
#include <gsl/gsl_linalg.h>

int main(int argc, char** argv) {
  using namespace std;
 
  MPI_Init(&argc, &argv);

  int world_size, world_rank;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

  // Get the name of the processor
  char processor_name[MPI_MAX_PROCESSOR_NAME];
  int name_len;
  MPI_Get_processor_name(processor_name, &name_len);

  // Print off a hello world message
  cout << "Process " << world_rank << " of " << world_size
       << " says hello from " << processor_name << endl;

  double start = MPI_Wtime();

  const size_t N = 5000;
  gsl_matrix* A = gsl_matrix_alloc(N, N);
  gsl_permutation* p = gsl_permutation_alloc(N);
  int signum = 0;

  // srand(world_rank * 1234);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      gsl_matrix_set(A, i, j, drand48());

  int r = gsl_linalg_LU_decomp(A, p, &signum);
  //cout << r << endl;

  gsl_matrix_free(A);
  gsl_permutation_free(p);

  double my_time = MPI_Wtime() - start;
  cerr << my_time << endl;

  double* all_times = new double[world_size];
  MPI_Gather(&my_time, 1, MPI_DOUBLE, all_times, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
 
  if (world_rank == 0) {
    double min_time = *std::min_element(all_times, all_times + world_size);
    double max_time = *std::max_element(all_times, all_times + world_size);

    for (int i = 0; i < world_size; i++) {
      cout << i << " " << all_times[i] << endl;
    }
    cout << "min=" << min_time << endl;
    cout << "max=" << max_time << endl;
 
    delete[] all_times;
  }

  MPI_Finalize();
  return 0;
}
