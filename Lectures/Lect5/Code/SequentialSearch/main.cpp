#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {1,4,10};
    int key = 9;

    size_t i;

    for (i =0; i< v.size()&& key <= v[i]; ++i);

        if (i < v.size()){
            if(key == v[i])
                std::cout << key << " found";
            else
                std::cout << key << " not found";
        }
        else
            std::cout << key << " not found";

    int i =8;

    int *pi; //= &i;

    if (*pi == 9 && pi != nullptr   )// you risk segmentation fault!
        std::cout <<" pi is 9!!";

    if (pi != nullptr   && *pi == 9  )// first test for valid pointer or iterator
                                        // and then access!!

    return 0;
}
