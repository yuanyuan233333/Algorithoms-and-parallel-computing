#include "shift_inverse_power_iteration.h"

namespace eigenvalue {

    using linear_algebra::operator*;
    using linear_algebra::operator-;

    double shift_inverse_power_iteration::solve(const linear_algebra::square_matrix& A, const double& mu, const std::vector<double>& x0) const
    {
        linear_algebra::square_matrix B(A);
        for (std::size_t i = 0; i < B.size(); i++) {
            B(i,i) -= mu;
        }

        return inverse_power_iteration::solve(B, x0) + mu;
    }

} // eigenvalue