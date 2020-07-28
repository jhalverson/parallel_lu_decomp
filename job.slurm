#!/bin/bash
#SBATCH --job-name=cxx_mpi       # create a short name for your job
#SBATCH --nodes=1                # node count
#SBATCH --ntasks=40
#SBATCH --cpus-per-task=1        # cpu-cores per task (>1 if multi-threaded tasks)
#SBATCH --mem-per-cpu=4G         # memory per cpu-core (4G is default)
#SBATCH --time=00:10:00          # total run time limit (HH:MM:SS)
# SBATCH --exclude=tiger-h21c2n11

hostname

module purge
module load intel/19.0/64/19.0.5.281 intel-mpi/intel/2019.3/64
#module load openmpi/gcc/3.1.5/64
#srun ./lu

for i in 1 2 4 8 16 32 40
do
  echo N $i
  time srun -n $i ./lu
done
