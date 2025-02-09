/*
 * Check sudoku matrix
 */

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

const size_t SIZE = 9;

// Return 1 if key is in v; n_elements is v size
int search_key (const unsigned v[], unsigned n_elements, unsigned key);

// Return 1 if v includes all numbers in [1,9]; n_elements is v size
int basic_search (const unsigned v[], unsigned n_elements);

// Return 1 if all sudoku matrix rows comply to the Sudoku rules
int check_rows (const unsigned sudoku[][SIZE]);

// Return 1 if all sudoku matrix columns comply to the Sudoku rules
int check_cols (const unsigned sudoku[][SIZE]);

// Return 1 if all sudoku matrix regions comply to the Sudoku rules
int check_regions (const unsigned sudoku[][SIZE]);

// Return:
//         1 if sudoku matrix complies to all Sudoku rules
//        -1 if a row violates the game rules
//        -2 if a column violates the game rules
//        -3 if a region violates the game rules
int check_sudoku(const unsigned sudoku[][SIZE]);

// Create a Sudoku matrix my Lewis' Algorithm
// (https://en.wikipedia.org/wiki/Sudoku_solving_algorithms)
void generate_sudoku(unsigned sudoku[][SIZE]);

int main()
{
    // initialize a sudoku matrix
    unsigned sudoku[SIZE][SIZE] = {
            {1,2,3,4,5,6,7,8,9},
            {2,3,4,5,6,7,8,9,1},
            {3,4,5,6,7,8,9,1,2},
            {4,5,6,7,8,9,1,2,3},
            {5,6,7,8,9,1,2,3,4},
            {6,7,8,9,1,2,3,4,5},
            {7,8,9,1,2,3,4,5,6},
            {8,9,1,2,3,4,5,6,7},
            {9,1,2,3,4,5,6,7,8}
    };

    // check
    int res = check_sudoku(sudoku);
    cout << "check_sudoku returns: " <<  res << endl;

    // initialize another sudoku matrix
    unsigned sudoku2[SIZE][SIZE];
    generate_sudoku(sudoku2);

    // check
    res = check_sudoku(sudoku2);
    cout << "check_sudoku returns: " <<  res << endl;

    return 0;
}

int search_key (const unsigned v[], unsigned n_elements, unsigned key)
{
    int key_found = 0;

    for (size_t i=0; i<n_elements; ++i)
        if (v[i] == key)
            key_found = 1;

    return key_found;
}

int basic_search (const unsigned v[], unsigned n_elements)
{
    int found = 1;

    for (size_t i=1; i<=n_elements && found==1; ++i)
        found = search_key(v, n_elements, i);

    return found;
}

int check_rows (const unsigned sudoku[][SIZE])
{
    unsigned v[SIZE];
    int ris = 1;

    for (size_t i=0; i<SIZE && ris==1; ++i)
    {
        // copy row to array v
        // REMEMBER: array must be copied element by element
        for (size_t j=0; j<SIZE; ++j)
            v[j] = sudoku[i][j];

        // check if v includes all integers between 1 and SIZE
        ris = basic_search(v, SIZE);

        /*
         * Alternative call:
         * ris = basic_search(sudoku[i], SIZE);
         *
         * And you don't need to copy elements to v!
         * Why is that possible!?
         */

        //cout << "Row " << i << " ris: " << ris << endl;
    }
    return ris;
}

int check_cols (const unsigned sudoku[][SIZE])
{
    unsigned v[SIZE];
    int ris = 1;

    for (size_t i=0; i<SIZE && ris==1; ++i)
    {
        // copy column to array v
        for (size_t j=0; j<SIZE; ++j)
            v[j] = sudoku[j][i];

        // check if v includes all integers between 1 and SIZE
        ris = basic_search(v, SIZE);

        //cout << "Col " << i << " ris: " << ris << endl;
    }
    return ris;
}

int check_regions (const unsigned sudoku[][SIZE])
{
    unsigned v[SIZE];
    int ris = 1;

    for (size_t i=0; i<3 && ris==1; ++i)
    {
        for (size_t j=0; j<3 && ris==1; ++j)
        {
            size_t index = 0;

            for (size_t i1=3*i; i1<3*i+3; ++i1)
                for (size_t j1=3*j; j1<3*j+3; ++j1)
                    v[index++] = sudoku[i1][j1];

            // check if v includes all integers between 1 and SIZE
            ris = basic_search(v, SIZE);
        }
    }
    return ris;
}

int check_sudoku (const unsigned sudoku[][SIZE])
{
    int ris;

    // check rows
    ris = check_rows(sudoku);
    if (ris==0)
    {
        cout << "Rows rules are violated" << endl;
        return -1;
    }

    // check columns
    ris = check_cols(sudoku);
    if (ris==0)
    {
        cout << "Columns rules are violated" << endl;
        return -2;
    }

    // check regions
    ris = check_regions(sudoku);
    if (ris==0)
    {
        cout << "Regions rules are violated" << endl;
        return -3;
    }

    // If we reach here, no errors were found
    cout << "Matrix ok!" << endl;
    return 1;
}

void generate_sudoku(unsigned sudoku[][SIZE])
{
    unsigned x = 0;
    for (size_t i=1; i<=3; ++i)
    {
        for (size_t j=1; j<=3; ++j)
        {
            for (size_t k=1; k<=SIZE; ++k)
            {
                sudoku[3*(i-1)+j-1][k-1] = (x % SIZE) + 1;
                x++;
            }
            x += 3;
        }
        x++;
    }
}