//
// Created by Federica Filippini on 25/11/2019.
//

#include "FileManager.h"

using std::cerr;
using std::endl;
using std::string;
using std::ifstream;
using std::istringstream;

const FileManager::table_type& FileManager::parse_file (const std::string& filename, char d) {

    fields.clear();

    ifstream ifs(filename);

    if (ifs) {
        string line;
        while (getline(ifs, line)) {
            row_type row;
            istringstream iss(line);
            string elem;
            while (getline(iss, elem, d))
                row.push_back(elem);
            fields.push_back(row);
        }
    }
    else
        cerr << "ERROR in FileManager::parse_csv - file "
             << filename << " cannot be opened" << endl;

    return fields;
}
