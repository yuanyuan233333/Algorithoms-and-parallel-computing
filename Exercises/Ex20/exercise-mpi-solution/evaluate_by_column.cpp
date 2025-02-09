#include "evaluate_by_column.hpp"

using la::dense_matrix;

dense_matrix evaluate_by_column(const dense_matrix& A, const function_t& f)
{
  int rank(0), size(0);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  unsigned nrows = A.rows();
  unsigned ncols = A.columns();

  // result is a row vector
  dense_matrix result(1,ncols);
  for (unsigned j = rank; j < ncols; j+=size)
  {
    // extract column
    dense_matrix column(nrows,1);
    for (unsigned i = 0; i < nrows; ++i)
      column(i,0) = A(i,j);

    // compute result
    result(0,j) = f(column);
  }

  // loop over all elements
  for (unsigned j = 0; j < ncols; ++j)
  {
    // broadcast each element from the proper root
    int root = j % size;
    MPI_Bcast(&(result(0,j)), 1, MPI_DOUBLE, root, MPI_COMM_WORLD);
  }

  return result;
}

dense_matrix evaluate_by_column2(const dense_matrix& A, const function_t& f)
{
  int rank(0), size(0);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  unsigned nrows = A.rows();
  unsigned ncols = A.columns();
  unsigned n_local_cols = ncols / size;

  // result is a row vector
  dense_matrix local_result(1,n_local_cols);
  for (unsigned j = 0; j < n_local_cols; ++j)
  {
    // extract column
    dense_matrix column(nrows,1);
    for (unsigned i = 0; i < nrows; ++i)
      column(i,0) = A(i, j + rank * n_local_cols);

    // compute result
    local_result(0,j) = f(column);
  }

  // collect result
  dense_matrix result(1,ncols);
  MPI_Allgather(local_result.data(), n_local_cols, MPI_DOUBLE, result.data(),
                n_local_cols, MPI_DOUBLE, MPI_COMM_WORLD);

  return result;
}
