#include "convolutional_layer.hpp"

namespace convnet {

    convolutional_layer::convolutional_layer(std::size_t _s_filter, std::size_t _prev_depth, std::size_t _n_filters,
                                             std::size_t _s_stride, std::size_t _s_padding)
            : s_filter(_s_filter), prev_depth(_prev_depth), n_filters(_n_filters), s_stride(_s_stride),
              s_padding(_s_padding) {
        initialize();
    }

    void convolutional_layer::initialize() {
        for (std::size_t it = 0; it < n_filters; ++it) {
            tensor_3d filter(s_filter, s_filter, prev_depth);
            filter.initialize_with_random_normal(0.0, 3.0 / (2 * s_filter + prev_depth));
            filters.push_back(filter);
        }
    }

    tensor_3d convolutional_layer::evaluate(const tensor_3d &inputs) const {
        // Calculate the output dimensions based on the filter size, stride, and padding
        std::size_t n_out = (inputs.get_height() - s_filter + 2 * s_padding) / s_stride + 1;
        std::size_t m_out = (inputs.get_width() - s_filter + 2 * s_padding) / s_stride + 1;

        // Initialize the output tensor
        tensor_3d out(n_out, m_out, n_filters);
        out.initialize_with_zeros();

        // Iterate over each output position
        for (std::size_t i = 0; i < n_out; ++i) {
            std::size_t start_i = i * s_stride;
            for (std::size_t j = 0; j < m_out; ++j) {
                std::size_t start_j = j * s_stride;

                // For each filter
                for (std::size_t k = 0; k < n_filters; ++k) {
                    const tensor_3d &filter = filters[k];

                    // Check if filter depth matches input depth
                    if (filter.get_depth() != inputs.get_depth()) {
                        std::cerr << "Filter depth must match the input depth." << std::endl;
                        return out;
                    }
                    // Perform convolution at (start_i, start_j) with filter `k`
                    double res = 0.0;
                    for (std::size_t d = 0; d < inputs.get_depth(); ++d) {
                        for (std::size_t fh = 0; fh < filter.get_height(); ++fh) {
                            for (std::size_t fw = 0; fw < filter.get_width(); ++fw) {
                                res += filter(fh, fw, d) * inputs(start_i + fh, start_j + fw, d);
                            }
                        }
                    }
                    // Assign the result to the output tensor at position (i, j, k)
                    out(i, j, k) = res;
                }
            }
        }

        return out;
    }

    tensor_3d convolutional_layer::apply_activation(const tensor_3d &Z) const {
        return act_function.apply(Z);
    }

    tensor_3d convolutional_layer::forward_pass(const tensor_3d &inputs) const {
        return apply_activation(evaluate(inputs));
    }


    std::vector<std::vector<double>> convolutional_layer::get_parameters() const {
        std::vector<std::vector<double> > parameters;
        for (tensor_3d filter: filters) {
            parameters.push_back(filter.get_values());
        }
        return parameters;
    }

    void convolutional_layer::set_parameters(const std::vector<std::vector<double>> parameters) {
        for (std::size_t i = 0; i < n_filters; ++i) {
            filters[i].set_values(parameters[i]);
        }
    }

} // namespace