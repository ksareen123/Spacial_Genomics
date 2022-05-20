#include <iostream>
#include <string>
#include <sstream>
#include "CellDatabase.h"
#include "CellData.h"
#include <fstream>

using std::cout;
using std::string;
using std::fstream;
using std::ofstream;
using std::endl;
using std::stoi;

// Default constructor/destructor. Modify them if you need to.
CellDatabase::CellDatabase() : records{} {}
CellDatabase::~CellDatabase() {}


void CellDatabase::loadData(const string& filename) 
{
    string line;
    std::ifstream datafile(filename);
    if (!datafile) {
        cout << "Error: Unable to open" << endl;
        return;
    }
    getline(datafile, line);
    while (!datafile.eof()) {
        string id = "-1";
        double fov = -1;
        double vol = -1;
        double center_x = -1.0;
        double center_y = -1.0;
        double min_x = -1.0;
        double max_x = -1.0; 
        double min_y = -1.0; 
        double max_y = -1.0;

        string element;
        getline(datafile, line);
        if (line == "") {
            continue;
        }
        std::istringstream mystream(line); 
        
        getline(mystream, element, ','); // id
        if (mystream.fail() || element.size() == 0) {
            cout << "Error, Invalid input: " << line << endl;
            continue;
        }
        bool is_digit = true;
        for (size_t i = 0; i < element.length(); i++) {
            if (!isdigit(element[i]) || isspace(element[i])) {
                is_digit = false;
            }
        }
        if (is_digit == false) {
            cout << "Error, Invalid input: " << line << endl;
            continue;
        }
        else {
            id = element;
        }

        getline(mystream, element, ','); // fov
        if (mystream.fail() || element.size() == 0) {
            cout << "Error, Invalid input: " << line << endl;
            continue;
        }
        else {
            bool is_pass = true;
            for (size_t i = 0; i < element.length(); i++) {
                if (!isdigit(element[i])) {
                    is_pass = false;
                }
            }
            if (is_pass == false) {
                cout << "Error, Invalid input: " << line << endl;
                continue;
            }
            fov = stoi(element);
        }

        getline(mystream, element, ','); // volume
        if (mystream.fail() || element.size() == 0) {
            cout << "Error, Invalid input: " << line << endl;
            continue;
        }
        else {
            bool is_pass = true;
            bool has_dot = false;
            for (size_t i = 0; i < element.length(); i++) {
                if (!isdigit(element[i]) && (element[i] != '.')) {
                    is_pass = false;
                }
                if (element[i] == '.') {
                    if (has_dot == true) {
                        is_pass = false;
                    }
                    else {
                        has_dot = true;
                    }
                }
            }
            if (is_pass == false) {
                cout << "Error, Invalid input: " << line << endl;
                continue;
            }
            vol = stod(element);
        }

        getline(mystream, element, ','); // center_x
        if (mystream.fail() || element.size() == 0) {
            cout << "Error, Invalid input: " << line << endl;
            continue;
        }
        else {
            bool is_pass = true;
            bool has_dot = false;
            for (size_t i = 0; i < element.length(); i++) {
                if (i == 0) {
                    if (element[i] == '-') {
                        continue;
                    }
                }
                if (!isdigit(element[i]) && (element[i] != '.')) {
                    is_pass = false;
                }
                if (element[i] == '.') {
                    if (has_dot == true) {
                        is_pass = false;
                    }
                    else {
                        has_dot = true;
                    }
                }
            }
            if (is_pass == false) {
                cout << "Error, Invalid input: " << line << endl;
                continue;
            }
            center_x = stod(element);
        }

        getline(mystream, element, ','); // center_y
        if (mystream.fail() || element.size() == 0) {
            cout << "Error, Invalid input: " << line << endl;
            continue;
        }
        else {
            bool is_pass = true;
            bool has_dot = false;
            for (size_t i = 0; i < element.length(); i++) {
                if (i == 0) {
                    if (element[i] == '-') {
                        continue;
                    }
                }
                if (!isdigit(element[i]) && (element[i] != '.')) {
                    is_pass = false;
                }
                if (element[i] == '.') {
                    if (has_dot == true) {
                        is_pass = false;
                    }
                    else {
                        has_dot = true;
                    }
                }
            }
            if (is_pass == false) {
                cout << "Error, Invalid input: " << line << endl;
                continue;
            }
            center_y = stod(element);
        }
        
        getline(mystream, element, ','); // min_x
        if (mystream.fail() || element.size() == 0) {
            cout << "Error, Invalid input: " << line << endl;
            continue;
        }
        else {
            bool is_pass = true;
            bool has_dot = false;
            for (size_t i = 0; i < element.length(); i++) {
                if (i == 0) {
                    if (element[i] == '-') {
                        continue;
                    }
                }
                if (!isdigit(element[i]) && (element[i] != '.')) {
                    is_pass = false;
                }
                if (element[i] == '.') {
                    if (has_dot == true) {
                        is_pass = false;
                    }
                    else {
                        has_dot = true;
                    }
                }
            }
            if (is_pass == false) {
                cout << "Error, Invalid input: " << line << endl;
                continue;
            }
            min_x = stod(element);
        }

        getline(mystream, element, ','); // max_x
        if (mystream.fail() || element.size() == 0) {
            cout << "Error, Invalid input: " << line << endl;
            continue;
        }
        else {
            bool is_pass = true;
            bool has_dot = false;
            for (size_t i = 0; i < element.length(); i++) {
                if (i == 0) {
                    if (element[i] == '-') {
                        continue;
                    }
                }
                if (!isdigit(element[i]) && (element[i] != '.')) {
                    is_pass = false;
                }
                if (element[i] == '.') {
                    if (has_dot == true) {
                        is_pass = false;
                    }
                    else {
                        has_dot = true;
                    }
                }
            }
            if (is_pass == false) {
                cout << "Error, Invalid input: " << line << endl;
                continue;
            }
            max_x = stod(element);
        }

        getline(mystream, element, ','); // min_y
        if (mystream.fail() || element.size() == 0) {
            cout << "Error, Invalid input: " << line << endl;
            continue;
        }
        else {
            bool is_pass = true;
            bool has_dot = false;
            for (size_t i = 0; i < element.length(); i++) {
                if (i == 0) {
                    if (element[i] == '-') {
                        continue;
                    }
                }
                if (!isdigit(element[i]) && (element[i] != '.')) {
                    is_pass = false;
                }
                if (element[i] == '.') {
                    if (has_dot == true) {
                        is_pass = false;
                    }
                    else {
                        has_dot = true;
                    }
                }
            }
            if (is_pass == false) {
                cout << "Error, Invalid input: " << line << endl;
                continue;
            }
            min_y = stod(element);
        }
        

        getline(mystream, element, ','); // max_y
        if (mystream.fail() || element.size() == 0) {
            cout << "Error: Invalid input: " << line << endl;
            continue;
        }
        else {
            bool is_pass = true;
            bool has_dot = false;
            for (size_t i = 0; i < element.length(); i++) {
                if (i == 0) {
                    if (element[i] == '-') {
                        continue;
                    }
                }
                if (!isdigit(element[i]) && (element[i] != '.')) {
                    is_pass = false;
                }
                if (element[i] == '.') {
                    if (has_dot == true) {
                        is_pass = false;
                    }
                    else {
                        has_dot = true;
                    }
                }
            }
            if (is_pass == false) {
                cout << "Error, Invalid input: " << line << endl;
                continue;
            }
            max_y = stod(element);
        }
        
        getline(mystream, element);
        if (!mystream.fail() || element.size() == 0) {
            cout << "Error: Invalid input: " << line << endl;
            continue;
        }
        if (id == "-1" || id == "") {
            cout << "Error: Invalid input: " << line << endl;
            continue;
        }
        /*
        if (max_x < min_x || center_x <= min_x || center_x >= max_x) {
            cout << "Error: Invalid input: " << line << endl;
            continue;
        }
        else if (max_y < min_y || center_y <= min_y || center_y >= max_y) {
            cout << "Error: Invalid input: " << line << endl;
            continue;
        }
        */
        if (fov < 0 || vol <= 0 /*|| center_x < 0 || center_y < 0 || min_x < 0 || min_y < 0 || max_x < 0 || max_y < 0 */) {
            cout << "Error: Invalid input: " << line << endl;
            continue;
        }
        records.insert(id, fov, vol, center_x, center_y, min_x, max_x, min_y, max_y);
        //cout << "inserted" << id << endl;
    }
    // Implement this function
}

// Do not modify
void CellDatabase::outputData(const string& filename) {
    ofstream dataout("sorted." + filename);

    if (!dataout.is_open()) 
    {
        cout << "Error: Unable to open " << filename << endl;
        exit(1);
    }
    dataout << records.print();
}

void CellDatabase::performQuery(const string& filename) 
{
    std::ifstream datastream(filename);
    // if (!datastream.is_open()) {
    //     return;
    // }

    std::ofstream output("result.data");
    string line;
    string query_type;

    while (!datastream.eof()) {
        getline(datastream, line);
        if (line == "") {
            continue;
        }
        std::stringstream linestream(line);
        linestream >> query_type;
        if (query_type == "AVG") {
            int k;
            linestream >> k;
            // string garbage;
            // linestream >> garbage;
            if (!linestream.eof() || k < 0) {
                // cout << "Error, Invalid input: " << line << endl;
                output << "Error, Invalid input: " << line << endl;
                continue;
            }
            else {
                //cout << "AVG " << k << ": " << records.average(k) << endl;
                output << "AVG " << k << ": " << records.average(k) << endl;
            }
        }
        else if (query_type == "VAR") {
            int k;
            linestream >> k;
            if (linestream.fail() || linestream.bad() || k < 0) {
                // cout << "Error, Invalid input: " << line << endl;
                output << "Error, Invalid input: " << line << endl;
                continue;
            }
            string garbage;
            linestream >> garbage;
            if (!linestream.fail()) {
                // cout << "Error, Invalid input: " << line << endl;
                output << "Error, Invalid input: " << line << endl;
                continue;
            }
            else {
                //cout << "VAR " << k << ": " << records.variance(k) << endl;
                output << "VAR " << k << ": " << records.variance(k) << endl;
            }
        }
        else if (query_type == "COUNT") {
            int k;
            linestream >> k;
            if (linestream.fail() || linestream.bad() || k < 0) {
                // cout << "Error, Invalid input: " << line << endl;
                output << "Error, Invalid input: " << line << endl;
                continue;
            }
            string garbage;
            linestream >> garbage;
            if (!linestream.fail()) {
                // cout << "Error, Invalid input: " << line << endl;
                output << "Error, Invalid input: " << line << endl;
                continue;
            }
            else {
                //cout << "COUNT " << k << ": " << records.countN(k) << endl;
                output << "COUNT " << k << ": " << records.countN(k) << endl;
            }
        }
        else if (query_type == "OUTLIER") {
            int fov;
            linestream >> fov;
            if (linestream.fail() || linestream.bad() || fov < 0) {
                // cout << "Error, Invalid input: " << line << endl;
                output << "Error, Invalid input: " << line << endl;
                continue;
            }
            int k;
            int N;
            linestream >> k >> N;
            if (linestream.fail() || linestream.bad() || N < 0) {
                // cout << "Error, Invalid input: " << line << endl;
                output << "Error, Invalid input: " << line << endl;
                continue;
            }
            string garbage;
            linestream >> garbage;
            if (!linestream.fail()) {
                // cout << "Error, Invalid input: " << line << endl;
                output << "Error, Invalid input: " << line << endl;
                continue;
            }
            else {
                //cout << "OUTLIER " << fov << " " << k << " " << N << ": " << records.outliers(fov, k, N) << endl;
                output << "OUTLIER " << fov << " " << k << " " << N << ": " << records.outliers(fov, k, N) << endl;
            }
        }
        else if (query_type == "") {
            line = "";
            linestream.clear();
            break;
        }
        else {
            // cout << "Error, Invalid input: " << line << endl;
            output << "Error, Invalid input: " << line << endl;
            continue;
        }
    }
        // Implement this function
}
