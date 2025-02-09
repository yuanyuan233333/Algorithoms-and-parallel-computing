#ifndef BLOCKMATRIX_H_
#define BLOCKMATRIX_H_

#include <vector>

#include "block.hpp"

class BlockMatrix: public Matrix
{
    public:
        BlockMatrix();

        ??? operator () (std::size_t i, std::size_t j) ???;

        ??? operator () (std::size_t i, std::size_t j) ???;
};

#endif /* BLOCKMATRIX_H_ */
