#include <iostream>

class Student {
public:
    void set_SID(int x);
    void prt_SID();
    void set_GPA(float x);
    void prt_GPA();
    void reset();
    float get_GPA();
    Student();
private:
    int SID;
    float GPA;
};

void Student::set_SID(int x) {
    SID = x;
}

void Student::prt_SID() {
    std::cout << SID;
}

void Student::set_GPA(float x) {
    GPA = x;
}

void Student::prt_GPA() {
    std::cout << GPA;
}

void Student::reset() {
    SID = -1;
    GPA = -1.0;
}

float Student::get_GPA() {
    return GPA;
}

Student::Student() {
    SID = -1;
    GPA = -1.0;
}

class University {
public:
    void set_Stu(Student x[]);
    float GPA_mean();
    float GPA_max();
    float GPA_min();
    University();
private:
    Student Sooner[5];
};

void University::set_Stu(Student x[]) {
    for (int i = 0; i < 5; i++) {
        Sooner[i] = x[i];
    }
}

float University::GPA_mean() {
    float sum = 0.0;
    for (int i = 0; i < 5; i++) {
        sum += Sooner[i].get_GPA();
    }
    float mean = sum / 5;
    std::cout << mean;
    return mean;
}

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

University::University() {
    for (int i = 0; i < 5; i++) {
        Sooner[i].reset();
    }
}

int main() {
    Student x[5];
    University OU;

    for (int i = 0; i < 5; i++) {
        x[i].prt_SID();
        std::cout << ' ';
        x[i].prt_GPA();
        std::cout << std::endl;
    }

    // std::cout << "Please enter Student ID followed by GPA" << std::endl;

    for (int i = 0; i < 5; i++) {
        int sid;
        float gpa;
        std::cin >> sid >> gpa;
        x[i].set_SID(sid);
        x[i].set_GPA(gpa);
    }

    for (int i = 0; i < 5; i++) {
        x[i].prt_SID();
        std::cout << ' ';
        x[i].prt_GPA();
        std::cout << std::endl;
    }

    OU.set_Stu(x);
    OU.GPA_mean();
    std::cout << ' ';
    OU.GPA_max();
    std::cout << ' ';
    OU.GPA_min();
    std::cout << std::endl;

    for (int i = 0; i < 5; i++) {
        x[i].reset();
        x[i].prt_SID();
        std::cout << ' ';
        x[i].prt_GPA();
        std::cout << std::endl;
    }

    return 0;
}
