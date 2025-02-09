#include <iostream>
#include <unordered_map>

#include "FileManager.h"

/* TODO:
1)  FileManager::parse_file() (in new .cpp)
2A) add_students()
2B) add_exames()
3)  average grade of each student in main()
*/

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
    for (students_type::const_iterator cit = students.cbegin(); 
         cit != students.cend(); ++cit) 
    {
        cout << "id: " << cit->first << "; ";
        const StudentsData& student = cit->second;
        float avg = student.average_grade();
        cout << "average grade: " << avg << endl;
    }

}

void add_students (const table_type& fields, students_type& students) {

    for (const row_type& row : fields) {
        unsigned id = std::stoi(row[0]);
        StudentsData new_student(row[1], row[2], row[3]);
        students.insert({id, new_student});
    }
}

void add_exams (const table_type& fields, students_type& students) {

    for (const row_type& row : fields) {

        unsigned id = std::stoi(row[0]);
        students_type::iterator it = students.find(id);
        if (it != students.end()) {
            StudentsData& student = it->second;
            Exam new_exam(std::stoi(row[1]), row[2], std::stoi(row[3]));
            student.add_exam(new_exam);
        }
        else
            cerr << "ERROR in add_exams: it is not possible to add exams "
                 << "to a non existing student"
                 << endl;
    }
}