#include "inverse_power_iteration.h"

namespace eigenvalue {

    using linear_algebra::operator*;
    using linear_algebra::operator-;

    double inverse_power_iteration::solve(const linear_algebra::square_matrix& A, const std::vector<double>& x0) const
    {
        linear_algebra::square_matrix L;
        linear_algebra::square_matrix U;
        linear_algebra::lu(A, L, U);

        double lambda = 0;
        double lambdaOld = 1.;	    	//current and old value of the min eigenvalue
        double res = tolerance + 1;		//res norm of the vector A*x_k - lambda_k*x_k
        double inc = tolerance + 1;		//increment: relative difference of lambda_k between two iterations
        std::size_t it = 0;				//number of iterations

        std::vector<double> yk(x0);
        linear_algebra::normalize(yk);
        std::vector<double> tmp;

        //implementing the inverse power iteration method:
        //while(not convergence):
        //	x^(k) = A^(-1)*x^(k-1);
        // 	normalize(x^(k));
        //  1/lambda_k = (y^(k), A^(-1)*y^(k)) or equivalently lambda_k = (y^(k), A*y^(k))
        while (!converged(res, inc) && it < max_it) {
            //updating yk
            tmp = linear_algebra::forwardsolve(L, yk);
            yk = linear_algebra::backsolve(U, tmp);
            linear_algebra::normalize(yk);

            //updating lambda_k
            tmp = A*yk; //I use again tmp to store this result
            lambda = linear_algebra::scalar(yk, tmp);

            //updating increment and residual
            inc = std::abs(lambda - lambdaOld)/std::abs(lambdaOld);
            res = linear_algebra::norm(tmp - lambda*yk);

            lambdaOld = lambda;
            it++;
        }

        if (it == max_it) {
            std::cerr << "Warning: method does not converge in the number of iterations set." << std::endl;
        }

        return lambda;
    }

    bool inverse_power_iteration::converged(const double& residual, const double& increment) const
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