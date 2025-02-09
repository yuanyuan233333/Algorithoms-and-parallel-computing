#include <algorithm>
#include <cmath>
#include <random>

#include "FunctionMin.hpp"

//gradient descent with x_init initial point
double FunctionMin::solve (double x_init) const
{
  Function df = f.derivative();

  double x0 = x_init;
  double f0 = f.eval(x0);

  // check convergence

  // Converged if:
  //    |(x0 - x1)| < tolerance or
  //    |(f0 - f1)| < tolerance or
  //    |df(x1)| < tolerance

  bool converged = (sup_limit - inf_limit) < tolerance || std::abs(df.eval(x0)) < tolerance;

  // until we converge or we reach max iterations....
  for (size_t i = 0; i < max_iterations && ! converged; ++i)
  {
      // evaluate derivative
      const double der_x0 = df.eval(x0);  // f'(x_{i-1})

      // compute next point     x_i = x_{i-1} - \delta * f'(x_{i-1})
      double x1 = x0 - step * der_x0;

      if (der_x0 > 0)
          x1 = std::max(x1, inf_limit);
          //if (x1 < inf_limit)
          //    x1 = inf_limit;

      if (der_x0 < 0)
          x1 = std::min(x1, sup_limit);
          // if (x1 > sup_limit)
          //      x1 = sup_limit;

      // compute new function value
      const double f1 = f.eval(x1);

      // check convergence
      converged = std::abs(x0 - x1) < tolerance or
                  std::abs(f0 - f1) < tolerance or
                  std::abs(df.eval(x1)) < tolerance;

      x0 = x1;
      f0 = f1;
  }

  return x0;
}

// gradient descent
double FunctionMin::solve (void) const
{
    return solve((inf_limit + sup_limit) / 2);
}

// gradient descent with multi-start
double FunctionMin::solve_multistart (unsigned n_trials) const
{
    std::default_random_engine generator(4850);
    std::uniform_real_distribution<double> distribution (inf_limit,
                                                         sup_limit);

    double x_min = solve();
    double fmin = f.eval(x_min);

    for (unsigned n = 1; n < n_trials; ++n)
    {
        const double x_guess = distribution(generator);  // that's a callable object

        double x_guess_min = solve(x_guess);

        if (f.eval(x_guess_min) < fmin){
            x_min = x_guess_min;
            fmin = f.eval(x_guess_min);
        }
    }

    return x_min;
}

// gradient descent with multi-start and domain decomposition
double FunctionMin::solve_domain_decomposition (unsigned n_intervals,
                                                unsigned n_trials) const
{
  double x_min = inf_limit;
  double f_min = f.eval(x_min);
  
  double length_subinterval = (sup_limit - inf_limit)/n_intervals;

  for (std::size_t sub_interval = 0; sub_interval < n_intervals; ++sub_interval){
      double inf_limit_sub = inf_limit + sub_interval * length_subinterval;
      double sup_limit_sub = inf_limit + (sub_interval+1) * length_subinterval;

      FunctionMin fmin_sub(f, inf_limit_sub, sup_limit_sub, tolerance, step, max_iterations);
      double x_min_sub = fmin_sub.solve_multistart(n_trials);

      if (f.eval(x_min_sub) < f_min){
          f_min = f.eval(x_min_sub);
          x_min = x_min_sub;
      }
  }

  return x_min;
}
