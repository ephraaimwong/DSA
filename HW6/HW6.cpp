// HW6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>
using namespace std;

vector<string> readName(const string &filename) {
    vector<string> nameList;
    ifstream file(filename);
    if (file.is_open()) {
        string name;
        while (getline(file, name)) {
            nameList.push_back(name);
        }
        file.close();
    }
    return nameList;
    //do {
    //    //cout << "Enter namelist file";
    //    //cin >> filename;
    //    file.open(filename);
    //    if (!file) { cerr << "Invalid File, try again" << endl; }
    //} while (!file);

}
unordered_map<string, int> findMissing( const string &filename, const vector<string> &nameList) {
    unordered_map<string, int> tally;
    for (const string& i : nameList) {
        tally[i] = 0;
    }
    ifstream file(filename);
    if (file.is_open()) {
        string assignment;
        while (getline(file, assignment)) {
            string delimit = "_";
            size_t pos = assignment.find(delimit);
            if (pos != string::npos) {
                string student = assignment.substr(0, pos);
                //cout << "Student: " << student << endl;
                if (tally.find(student) != tally.end()) {
                    tally[student]++;
                }
            }
        }
        file.close();
    }
    return tally;
}
int main()
{
    string namefile;string assignmentfile;bool validFile1 = false;bool validFile2 = false;vector<string>  students;
    do {
        
        cout << "Enter students file: ";
        cin >> namefile;
        cout << endl;
        students = readName(namefile);
        //if (students.empty()) { cout << "Enter students file: "; }
        if (!students.empty()){ validFile1 = true; }
    } while (!validFile1);



    do {
        cout << "Enter assignments file: ";
        cin >> assignmentfile;
        cout << endl;
        ifstream file(assignmentfile);
        if (file.good()) { validFile2 = true; }
        //else { cout << "Enter assignments file: "; }
    } while (!validFile2);

    unordered_map<string, int> missingAssignment = findMissing(assignmentfile, students);


    for (const auto& i : missingAssignment) {
        int missing = 9 - i.second;
        if (missing > 0) {
            cout << i.first << ": " << missing << " assignments missing" << endl;
        }
    }
    return 0;
}