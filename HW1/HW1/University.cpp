#include "University.h"
#include <iostream>
//class University {
//public:
//	void set_Stu(Student x[]);
//	float GPA_mean();
//	float GPA_min();
//	float GPA_max();
//	University();
//private:
//	Student Sooner[5];
//};

void University::set_Stu(Student x[])
{
	for (int i = 0; i < 5;i++) {
		Sooner[i] = x[i];
	}
}

float University::GPA_mean()
{
	float sum =0.0;
	for (int i = 0;i < 5; i++) {
		sum += Sooner[i].get_GPA();
	}
	float mean = sum / 5;
	std::cout << mean;return mean;
}

float University::GPA_max()
{
	float currMax=0.0;
	for (int i = 0;i < 5;i++) {
		if (Sooner[i].get_GPA() > currMax) {
			currMax = Sooner[i].get_GPA();
		}
	}
	std::cout << currMax;return currMax;
}

float University::GPA_min()
{
	float currMin=Sooner[0].get_GPA();
	for (int i = 0;i < 5;i++) {
		if (Sooner[i].get_GPA() < currMin) {
			currMin = Sooner[i].get_GPA();
		}
	}
	std::cout << currMin;return currMin;
}

University::University()
{
	for (int i = 0; i < 5;i++) {
		Sooner[i].reset();
	}
}