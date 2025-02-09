#include <iostream>
#include <mpi.h>
#include <vector>

#include "input.hh"
#include "output.hh"
#include "vector_sum.hh"

int main (int argc, char *argv[])
{
  MPI_Init (&argc, &argv);

  int rank, size;
  MPI_Comm_rank (MPI_COMM_WORLD, &rank);
  MPI_Comm_size (MPI_COMM_WORLD, &size);

  unsigned n = 0;
  if (rank == 0) std::cin >> n;

  MPI_Bcast (&n, 1, MPI_UNSIGNED, 0, MPI_COMM_WORLD);

  const std::vector<double> x = mpi::read_vector (n, "x", MPI_COMM_WORLD);
  const std::vector<double> y = mpi::read_vector (n, "y", MPI_COMM_WORLD);

  using numeric::operator +;
  const std::vector<double> z =  x +  y;

  mpi::print_vector (z, n, "Result vector 'z':", MPI_COMM_WORLD);

  MPI_Finalize ();
  return 0;
}
