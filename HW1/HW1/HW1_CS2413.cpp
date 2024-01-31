#include <iostream>
// was originally coded as header and cpp files before merger for purposes of submission

//student.h file
class Student {
public:
    //public methods, defined in cpp file
    void set_SID(int x);
    void prt_SID();
    void set_GPA(float x);
    void prt_GPA();
    void reset();
    float get_GPA();
    Student();
private:
    //private fields
    int SID;
    float GPA;
};

//student.cpp file
//setter StudentID
void Student::set_SID(int x) {
    SID = x;
}
//print StudentID
void Student::prt_SID() {
    std::cout << SID;
}
//setter GPA
void Student::set_GPA(float x) {
    GPA = x;
}
//print GPA
void Student::prt_GPA() {
    std::cout << GPA;
}
//reset method to clear Student list
void Student::reset() {
    SID = -1;
    GPA = -1.0;
}
//getter GPA
float Student::get_GPA() {
    return GPA;
}
//constructor
Student::Student() {
    SID = -1;
    GPA = -1.0;
}

//university.h file
class University {
public:
    //public methods
    void set_Stu(Student x[]);
    float GPA_mean();
    float GPA_max();
    float GPA_min();
    University();
private:
    //private field
    Student Sooner[5];
};

//university.cpp file
//set student from list
void University::set_Stu(Student x[]) {
    for (int i = 0; i < 5; i++) {
        Sooner[i] = x[i];
    }
}
//calculate mean GPA from list of students
float University::GPA_mean() {
    float sum = 0.0;
    for (int i = 0; i < 5; i++) {
        sum += Sooner[i].get_GPA();
    }
    float mean = sum / 5;
    std::cout << mean;
    return mean;
}
//get highest GPA from list of students
float University::GPA_max() {
    float currMax = 0.0;
    for (int i = 0; i < 5; i++) {
        if (Sooner[i].get_GPA() > currMax) {
            currMax = Sooner[i].get_GPA();
        }
    }
    std::cout << currMax;
    return currMax;
}
//get lowest GPA from list of students
float University::GPA_min() {
    float currMin = Sooner[0].get_GPA();
    for (int i = 0; i < 5; i++) {
        if (Sooner[i].get_GPA() < currMin) {
            currMin = Sooner[i].get_GPA();
        }
    }
    std::cout << currMin;
    return currMin;
}
//constructor
University::University() {
    for (int i = 0; i < 5; i++) {
        //initialize list of students as -1
        Sooner[i].reset();
    }
}

int main() {
    Student x[5];
    University OU;

    //print status of SID and GPA of all students in list
    for (int i = 0; i < 5; i++) {
        x[i].prt_SID();
        std::cout << ' ';
        x[i].prt_GPA();
        std::cout << std::endl;
    }

    // std::cout << "Please enter Student ID followed by GPA" << std::endl;
    // call for user input SID and GPA and set values to student object.
    for (int i = 0; i < 5; i++) {
        int sid;
        float gpa;
        std::cin >> sid >> gpa;
        x[i].set_SID(sid);
        x[i].set_GPA(gpa);
    }
    //print status of SID and GPA of all students in list
    for (int i = 0; i < 5; i++) {
        x[i].prt_SID();
        std::cout << ' ';
        x[i].prt_GPA();
        std::cout << std::endl;
    }
    //enter student list objects into University's student list
    OU.set_Stu(x);
    //get mean GPA
    OU.GPA_mean();
    std::cout << ' ';
    //get highest GPA
    OU.GPA_max();
    std::cout << ' ';
    //get lowest GPA
    OU.GPA_min();
    std::cout << std::endl;

    for (int i = 0; i < 5; i++) {
        //reset student object value, print SID and GPA, loop to next
        x[i].reset();
        x[i].prt_SID();
        std::cout << ' ';
        x[i].prt_GPA();
        std::cout << std::endl;
    }

    return 0;
}
