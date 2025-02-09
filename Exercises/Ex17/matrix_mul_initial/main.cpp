#include <fstream>
#include <iostream>

#include <mpi.h>

#include "dense_matrix.hh"

int
main (int argc, char *argv[])
{
  MPI_Init (&argc, &argv);

  int rank (0), size (0);
  MPI_Comm_rank (MPI_COMM_WORLD, &rank);
  MPI_Comm_size (MPI_COMM_WORLD, &size);

  la::dense_matrix full_A(0, 0);
  la::dense_matrix full_B(0, 0);

  if (rank == 0)
    {
      std::ifstream first (argv[1]), second (argv[2]);
      full_A.read (first);
      full_B.read (second);
    }

  unsigned m = full_A.rows(), n = full_A.columns(), p = full_B.columns();
  
  // Your code goes here

  la::dense_matrix full_C (m, p);

  // Your code goes here
  
  if (rank == 0)
    {
      std::cout << full_C.rows() << " " << full_C.columns() << "\n";

      for (std::size_t i = 0; i < full_C.rows(); ++i)
        for (std::size_t j = 0; j < full_C.columns(); ++j)
          {
            std::cout << full_C(i, j);
            std::cout << (full_C.columns() - j == 1 ? "\n" : " ");
          }
    }

  MPI_Finalize ();
  return 0;
}
