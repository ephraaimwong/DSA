#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <iomanip> 

using namespace std;
//read student name from file
vector<string> readNames(const string& filename) {
    vector<string> names;
    ifstream file(filename); // open file for reading
    string name;
    //read each line till end of file
    while (getline(file, name)) {
        names.push_back(name); // add read name to vector
    }
    file.close();
    return names;
}
//tally assignments for each student
unordered_map<string, int> tallyAssignments(const string& filename, const vector<string>& names) {
    //Map to store assignment tally for each student
    unordered_map<string, unordered_set<int>> tally; // Using unordered_set to prevent counting duplicates
    ifstream file(filename); // open file for reading
    string assignment;
    //read line till end of file
    while (getline(file, assignment)) {
        // Extract student name and assignment number from the assignment
        size_t pos = assignment.find("_");
        string student = assignment.substr(0, pos);//read substring from index 0 to "_" aka name
        int assignmentNumber = stoi(assignment.substr(pos + 2)); // Extract the assignment number
        tally[student].insert(assignmentNumber);// Increment the count for the assignment for the student
    }
    file.close();

    // Convert the unordered_set counts to int counts
    unordered_map<string, int> result;

    for (const auto& i : tally) {
        result[i.first] = i.second.size();//store assignment tally for each student
    }
    return result;
}

//calculate missing assignments for each student
unordered_map<string, int> calculateMissing(const unordered_map<string, int>& tally) {
    unordered_map<string, int> missing;
    //loop through tally map
    for (const auto& pair : tally) {
        int missingCount = 9 - pair.second; // Calculate missing assignments by total - submitted
        if (missingCount > 0) {
            missing[pair.first] = missingCount; //assign missing count to each student 
        }
        else {
            missing[pair.first] = 0; // No missing assignments
        }
    }
    return missing;
}

//print formatted missing assignments for each student
void printMissing(const unordered_map<string, int>& missing, const vector<string>& names) {
    cout << left << setw(20) << "NAME" << "MISSING ASSIGNMENTS" << endl;//header
    //loop through student names
    for (const auto& name : names) {
        int missingCount = missing.count(name) ? missing.at(name) : 0;//search for student name as key in missing map, if exist >> store value, if Does Not Exist >> missingCount = 0
        cout << left << setw(20) << name << missingCount << endl;
    }
}


int main() {
    string namefile;
    string assignmentfile;
    bool validFile1 = false;
    bool validFile2 = false;
    vector<string> students;

    // Prompt loop for entering the students file
    do {
        cout << "Enter students file: ";
        cin >> namefile;
        cout << endl;
        students = readNames(namefile);
        if (!students.empty()) {
            validFile1 = true;
        }
    } while (!validFile1); //keep looping until valid file

    // Prompt loop for entering the assignments file
    do {
        cout << "Enter assignments file: ";
        cin >> assignmentfile;
        cout << endl;
        ifstream file(assignmentfile);
        if (file.good()) {
            validFile2 = true;
        }
    } while (!validFile2); //keep looping until valid file

    // Tally assignments
    unordered_map<string, int> tally = tallyAssignments(assignmentfile, students);

    // Calculate missing assignments
    unordered_map<string, int> missing = calculateMissing(tally);

    // Output missing assignments
    printMissing(missing, students);

    return 0;
}


