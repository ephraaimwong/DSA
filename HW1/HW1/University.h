#ifndef UNIVERSITY_H
#define UNIVERSITY_H
#include "Student.h"
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
#endif // !UNIVERSITY_H

