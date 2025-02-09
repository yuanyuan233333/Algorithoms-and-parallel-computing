//
// Created by Danilo Ardagna on 07/11/2020.
//

#ifndef STATICQA_STUDENT_H
#define STATICQA_STUDENT_H

#include <string>

class Student {
    static unsigned autoID;
    static float alpha1;
    static float alpha2;
    static float beta1;
    static float beta2;
    static float beta3;

    unsigned ID;
    std::string full_name;
    float family_income;

public:

    float compute_taxes() const;

    static void set_alphas(float a1, float a2);
    static void set_betas(float b1, float b2, float b3);

    std::string to_string() const;

    Student(const std::string &fullName, float familyIncome);
};


#endif //STATICQA_STUDENT_H
