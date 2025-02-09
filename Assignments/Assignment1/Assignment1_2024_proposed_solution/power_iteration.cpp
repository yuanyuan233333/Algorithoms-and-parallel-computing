#include "power_iteration.h"

namespace eigenvalue {

    using linear_algebra::operator*;
    using linear_algebra::operator-;

    double power_iteration::solve(const linear_algebra::square_matrix& A, const std::vector<double>& x0) const
    {
        double lambda = 0;
        double lambdaOld = 1.;	    	//current and old value of the max eigenvalue
        double res = tolerance + 1;		//res norm of the vector A*x_k - lambda_k*x_k
        double inc = tolerance + 1;		//increment: relative difference of lambda_k between two iterations
        std::size_t it = 0;				//number of iterations

        std::vector<double> yk(x0);
        std::vector<double> xk;

        //implementing the power iteration
        //while(not convergence):
        //	y^(k) = A*y^(k-1)
        //	normalize(y^(k))
        //  lambda_k = (y^(k), A*y^(k))
        while (!converged(res, inc) && it < max_it) {
            //updating yk
            xk = yk;
            linear_algebra::normalize(xk);
            yk = A*xk;

            //updating lambda_k
            lambda = linear_algebra::scalar(xk, yk);

            //updating increment and residual
            inc = std::abs(lambda - lambdaOld)/std::abs(lambdaOld);
            res = linear_algebra::norm(yk - lambda*xk);

            lambdaOld = lambda;
            it++;
        }

        if (it == max_it) {
            std::cerr << "Warning: method does not converge in the number of iterations set." << std::endl;
        }

        return lambda;
    }

    bool power_iteration::converged(const double& residual, const double& increment) const
    {
        bool conv;

        switch(termination) {
            case(RESIDUAL):
                conv = residual < tolerance;
                break;
            case(INCREMENT):
                conv = increment < tolerance;
                break;
            case(BOTH):
                conv = residual < tolerance && increment < tolerance;
                break;
            default:
                conv = false;
        }
        return conv;
    }

} // eigenvalue