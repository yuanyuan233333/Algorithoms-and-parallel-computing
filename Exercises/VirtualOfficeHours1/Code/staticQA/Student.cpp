//
// Created by Danilo Ardagna on 07/11/2020.
//

#include "Student.h"


unsigned Student::autoID = 1;
float Student::alpha1 = 0;
float Student::alpha2 = 0 ;
float Student::beta1 = 0 ;
float Student::beta2 = 0 ;
float Student::beta3 = 0 ;

Student::Student(const std::string &fullName, float familyIncome) : full_name(fullName),
                    family_income(familyIncome) {
    ID = autoID;
    autoID++;
}

float Student::compute_taxes() const {

    if  (family_income < alpha1)
        return beta1 * family_income;
    else if ( (alpha1 <= family_income) && (family_income  < alpha2))
        return beta2 * family_income;
    else
        return beta3 * family_income;

}

void Student::set_alphas(float a1, float a2) {

    alpha1 = a1;
    alpha2 = a2;
}

void Student::set_betas(float b1, float b2, float b3) {
    beta1 = b1;
    beta2 = b2;
    beta3 = b3;
}

std::string Student::to_string() const {
    return std::to_string(ID) + " " + full_name + " " + std::to_string(family_income);
}
