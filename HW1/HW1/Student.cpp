#include "Student.h"
#include <iostream>
//class Student {
//public:
//	void set_SID(int x);
//	void prt_SID();
//	void set_GPA(float x);
//	void prt_GPA();
//	void reset();
//	float get_GPA();
//	Student();
//private:
//	int SID;
//	float GPA;
//};

void Student::set_SID(int x)
{
	SID = x;
}

void Student::prt_SID()
{
	std::cout << SID;
}

void Student::set_GPA(float x)
{
	GPA = x;
}

void Student::prt_GPA()
{
	std::cout << GPA;
}

void Student::reset()
{
	SID = -1;GPA = -1.0;
}

float Student::get_GPA()
{
	return GPA;
}

Student::Student()
{
	SID = -1;GPA = -1.0;
}