#include <iostream>

#include <mpi.h>

int
main (int argc, char *argv[])
{
  MPI_Init (&argc, &argv);

  int rank (0), size (0);
  MPI_Comm_rank (MPI_COMM_WORLD, &rank);
  MPI_Comm_size (MPI_COMM_WORLD, &size);

  int a=1;
  int b=0;
  int c=2;
  int d=0;

int MPI_Reduce (const void *sendbuf,
                void *recvbuf, int count,
                MPI_Datatype datatype,
                MPI_Op op, int dest,
                MPI_Comm comm);

  if (rank==0){
    MPI_Reduce(&a, &b, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    MPI_Reduce(&c, &d, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

  }
  else if (rank ==1){
    MPI_Reduce(&c, &d, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    MPI_Reduce(&a, &b, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

  }
  else if (rank ==2){
    MPI_Reduce(&a, &b, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    MPI_Reduce(&c, &d, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

  }

  MPI_Finalize ();
  return 0;
}