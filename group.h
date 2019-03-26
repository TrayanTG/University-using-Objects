#pragma once

#include "student.h"
#include "mentor.h"

class Group
{
	Mentor	 _mentor;
	Student *_students;
	char	 _students_count;
public:
	Group();
	Group(Mentor mentor, const Student *students, char studentsCount);

	Mentor getMentor()const;
	Student *getStudents()const;
	char getStudentsCount()const;
	bool studentAskQuestion(const Student &student);
};