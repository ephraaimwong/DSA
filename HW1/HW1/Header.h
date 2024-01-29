#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
using namespace std;
class Student {
private:
	std::string name;
	int GPA;

public:
	//constructor
	Student(const std::string& name, int GPA);
	//member func
	void set_SID();

};

#endif //STUDENT_H
