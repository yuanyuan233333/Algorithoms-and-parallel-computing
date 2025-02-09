#include "max_pooling_layer.hpp"

namespace convnet {

    max_pooling_layer::max_pooling_layer(std::size_t s_filter, std::size_t strd) {
        size_filter = s_filter;
        stride = strd;
    };

    tensor_3d max_pooling_layer::evaluate(const tensor_3d &inputs) const {
        // Calculate the output dimensions based on filter size and stride
        int n_out = (inputs.get_height() - size_filter) / stride + 1;
        int m_out = (inputs.get_width() - size_filter) / stride + 1;

        std::vector<double> out;
        out.reserve(n_out * m_out * inputs.get_depth());

        // Loop through the depth and each region of the input tensor
        for (std::size_t k = 0; k < inputs.get_depth(); ++k) {
            for (int i = 0; i < n_out; ++i) {
                for (int j = 0; j < m_out; ++j) {
                    // Temporary container to hold the values in the current pooling region
                    std::vector<double> pool_values;

                    // Iterate over the filter region
                    for (std::size_t di = 0; di < size_filter; ++di) {
                        for (std::size_t dj = 0; dj < size_filter; ++dj) {
                            pool_values.push_back(inputs(size_filter * i + di, size_filter * j + dj, k));
                        }
                    }

                    // Get the max value in the pool region and add to the output vector
                    //The function std::max_element in C++ is a function from the <algorithm> library,
                    // and it’s used to find the maximum element within a specified range, typically
                    // in a container like a std::vector.

                    out.push_back(*std::max_element(pool_values.begin(), pool_values.end()));
                }
            }
        }

        // Return the pooled tensor
        return tensor_3d(n_out, m_out, inputs.get_depth(), out);
    };


    tensor_3d max_pooling_layer::apply_activation(const tensor_3d &Z) const {
        return Z;
    };

    tensor_3d max_pooling_layer::forward_pass(const tensor_3d &inputs) const {
        return evaluate(inputs);
    };

    // Do nothing since max pooling has no learnable parameter
    void max_pooling_layer::set_parameters(const std::vector<std::vector<double>> parameters) {}

} // namespace