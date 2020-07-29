# LU decomposition per MPI process (weak scaling)

This embarrassingly parallel code performs the same LU decomposition of a square matrix on each MPI process. Besides an insignificant gather at the end of the run, there is no communication between processes. The number of CPU-cores is varied while the work that each CPU-core does is fixed.

## Tiger

```
$ module purge
$ module load intel/19.0/64/19.0.5.281 intel-mpi/intel/2019.3/64
$ make
$ sbatch job.slurm
```

## Perseus

```
$ module purge
$ module load intel/19.0/64/19.0.5.281 intel-mpi/intel/2018.3/64
$ make
$ sbatch job.slurm
```
