#ifndef STUDENT_H
#define STUDENT_H
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
#endif //STUDENT_H
