#include <iostream>

#include <vector>

#include "Student.h"

int main() {
    std::vector<Student> v;

    Student::set_alphas(10000,20000);
    Student::set_betas(0.1,0.2,0.3);

    v.push_back(Student("Alice", 9000));
    v.push_back(Student("Bob", 18000));
    v.push_back(Student("Markus", 33000));

    std::cout << "Students taxes this year " << std::endl;

    for (auto it =  v.cbegin(); it != v.cend(); ++it)
        std::cout << it->to_string() << " " << it->compute_taxes()<< std::endl;

    return 0;
}
