#include "output.hh"

#include <iostream>

namespace mpi
{
  void
  print_vector (std::vector<double> const & local_v, unsigned n,
                std::string const & title, MPI_Comm const & comm)
  {
    int rank, size;
    MPI_Comm_rank (comm, &rank);
    MPI_Comm_size (comm, &size);

    const unsigned local_n = local_v.size ();

    if (rank > 0)
      {
        // Here are only sending ranks, so no need for the receive buffer.
        MPI_Gather (local_v.data (), local_n, MPI_DOUBLE,
                    nullptr, local_n, MPI_DOUBLE,
                    0, comm);
      }
    else
      {
        std::vector<double> global (n);
        MPI_Gather (local_v.data (), local_n, MPI_DOUBLE,
                    global.data (), local_n, MPI_DOUBLE,
                    0, comm);

        std::cout << title << "\n";
        for (double value : global) std::cout << value << " ";
        std::cout << std::endl;
      }
  }
}
