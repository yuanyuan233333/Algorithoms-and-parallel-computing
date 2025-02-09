#ifndef INPUT_HH
#define INPUT_HH

#include <mpi.h>
#include <string>
#include <vector>

namespace mpi
{
  std::vector<double>
  read_vector (unsigned, std::string const &, MPI_Comm const &);
}

#endif // INPUT_HH
