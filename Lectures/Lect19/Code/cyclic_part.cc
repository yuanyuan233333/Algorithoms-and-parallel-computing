#include <mpi.h>

#include <iostream>
#include <vector>

using std::vector;

double f(double x);

double min_f (const vector<double> v);

int main (int argc, char *argv[])
{
  MPI_Init (&argc, &argv);
  int rank, size;
  vector<double> v = {1,2,3,4};

  MPI_Comm_size (MPI_COMM_WORLD, &size);
  MPI_Comm_rank (MPI_COMM_WORLD, &rank);

  double min_val = min_f(v);
  //std::cout << "Min f(x) is : " << min_val <<std::endl; // All processes knows the min and will print
  if (rank ==0) // To have a single print rank 0 print the minimum
     std::cout << "Min f(x) is : " << min_val <<std::endl;

  MPI_Finalize ();
  return 0;
}

double f(double x){
  return x*x;
}

double min_f (const vector<double> v)
  {
    int rank, size;
    MPI_Comm_rank (MPI_COMM_WORLD, &rank);
    MPI_Comm_size (MPI_COMM_WORLD, &size);

    double local_min = 1000;

    for (size_t i = rank; i < v.size (); i += size)
      {
        double f_x = f(v[i]);
        if (f_x < local_min)
          local_min = f_x;
      }

    double global_min;
    MPI_Allreduce (&local_min, &global_min, 1, MPI_DOUBLE,
                   MPI_MIN, MPI_COMM_WORLD);

    return global_min;
  }
