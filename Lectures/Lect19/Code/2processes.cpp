#include <cstdio>
#include <mpi.h>
#include <iostream>
#include <string>

using std::string;
int main (int argc, char *argv[])
{
  MPI_Init (&argc, &argv);
  int rank, size;
  MPI_Comm_size (MPI_COMM_WORLD, &size);
  MPI_Comm_rank (MPI_COMM_WORLD, &rank);

	// Send 2 characters!
	constexpr unsigned max_string = 2;


	if (rank > 0){
      string message("11111");
      //std::cout << rank << " " << message << std::endl;
  		MPI_Send (&message[0], max_string , MPI_CHAR,
            	  0, 0, MPI_COMM_WORLD);
  }
	else
  	{
      string message("00000");
    	std::cout << message << std::endl;
    	for (int r = 1; r < size; ++r)
      	{
          //std::cout << "Debug r: " << r << std::endl;
        	MPI_Recv (&message[0], max_string , MPI_CHAR, r, 0,
            	      MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        	std::cout << message << std::endl;
      	}
    }

  //std::cout << "Debug rank: " << rank << std::endl;

  MPI_Finalize ();
  return 0;
}
