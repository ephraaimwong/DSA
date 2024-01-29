#include "Student.h"
#include "University.h"
#include <iostream>
int main() {
	Student x[5];
	University OU;
	for (int i = 0; i < 5;i++) {
		x[i].prt_SID(); std::cout << ' ';
		x[i].prt_GPA(); std::cout << std::endl;
	}
	std::cout << "Please enter Student ID followed by GPA" << std::endl;
	for (int i = 0;i < 5;i++) {
		int sid; float gpa;
		std::cin >> sid >> gpa;
		x[i].set_SID(sid);x[i].set_GPA(gpa);
	}
	for (int i = 0;i < 5;i++) {
		x[i].prt_SID(); std::cout << ' ';
		x[i].prt_GPA(); std::cout << std::endl;
	}
	OU.set_Stu(x);OU.GPA_mean();std::cout << ' ';OU.GPA_max();std::cout << ' ';OU.GPA_min();std::cout << std::endl;
	for (int i = 0;i < 5;i++) {
		x[i].reset();
		x[i].prt_SID(); std::cout << ' ';
		x[i].prt_GPA(); std::cout << std::endl;
	}
	return 0;
}