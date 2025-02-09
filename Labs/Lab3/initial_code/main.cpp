#include <iostream>
#include <unordered_map>

#include "FileManager.h"

using std::unordered_map;
using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cerr;

typedef vector<string> row_type;
typedef vector<row_type> table_type;
typedef unordered_map<unsigned,StudentsData> students_type;

void add_students (const table_type&, students_type&);
void add_exams (const table_type&, students_type&);

int main () {

    string filename_students = "../students.txt";
    string filename_exams = "../exams.txt";

    students_type students;

    FileManager FM;

    // parse students file
    table_type fields = FM.parse_file(filename_students);

    // add students to the map
    add_students(fields, students);

    // parse exams file
    fields = FM.parse_file(filename_exams);

    // add exams to the corresponding students, if they exist in the map
    add_exams(fields, students);

    // compute and print average of students' grades
    
    /* Your code goes here */

}

void add_students (const table_type& fields, students_type& students) {

    /* Your code goes here */
}

void add_exams (const table_type& fields, students_type& students) {

    /* Your code goes here */
}