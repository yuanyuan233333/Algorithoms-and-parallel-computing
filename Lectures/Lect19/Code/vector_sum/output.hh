#ifndef OUTPUT_HH
#define OUTPUT_HH

#include <mpi.h>
#include <string>
#include <vector>

namespace mpi
{
  void
  print_vector (std::vector<double> const &, unsigned,
                std::string const &, MPI_Comm const &);
}

#endif // OUTPUT_HH
