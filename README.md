# Concurrent LU Decompositions

This embarrassingly parallel code has each process perform an LU decomposition of a square matrix.

```
$ module purge
$ module load intel/19.0/64/19.0.5.281 intel-mpi/intel/2019.3/64
$ make
$ sbatch job.slurm
```
