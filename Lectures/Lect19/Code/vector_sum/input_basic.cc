#include "input.hh"

#include <iostream>

namespace mpi
{
  std::vector<double>
  read_vector (unsigned n, std::string const & name, MPI_Comm const & comm)
  {
    int rank, size;
    MPI_Comm_rank (comm, &rank);
    MPI_Comm_size (comm, &size);

    const unsigned local_n = n / size;
    std::vector<double> result (local_n);

    if (rank == 0)
      {
        std::vector<double> input (n);

        std::cout << "Enter vector '" << name << "'\n";
        for (double & element : input) std::cin >> element;

        MPI_Scatter (input.data (), local_n, MPI_DOUBLE,
                     result.data (), local_n, MPI_DOUBLE,
                     0, comm);
      }
    else
      {
        // Here are only receiving ranks, so no need for the send buffer.
        MPI_Scatter (nullptr, local_n, MPI_DOUBLE,
                     result.data (), local_n, MPI_DOUBLE,
                     0, comm);
      }

    return result;
  }
}
