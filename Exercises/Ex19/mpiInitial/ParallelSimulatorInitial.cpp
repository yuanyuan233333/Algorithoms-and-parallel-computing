#include "ParallelSimulator.h"

namespace ParallelSimulator {

  void send_particle(const Particle& particle, int dest);

  Particle recv_particle(int src);

  void communicate_particles(int r, std::vector<std::vector<Particle>>& particles)
  {
    // YOUR CODE GOES HERE

    if (rank == r)
    {
      // rank r sends to each other_rank the particles stored in particles[other_rank]

      // YOUR CODE GOES HERE
    }
    else
    {
      // if the current rank is not r, it receives the particles from r and stores them in particles[rank]

      // YOUR CODE GOES HERE
    }
  }

};