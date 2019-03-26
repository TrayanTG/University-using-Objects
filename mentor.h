#pragma once
#include "student.h"

class Mentor : public Student
{

public:
	Mentor();
	bool helpStudent(Student &student);
};