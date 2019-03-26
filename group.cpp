#include "group.h"

Group::Group(): _students_count(0)
{

}

Group::Group(Mentor mentor, const Student *students, char studentsCount)
{
	_mentor = mentor;
	for (_students_count = 0;_students_count < studentsCount;_students_count++)
	{
		_students[_students_count] = students[_students_count];
	}
}

Mentor Group::getMentor()const
{
	return _mentor;
}

Student *Group::getStudents()const
{
	return _students;
}

char Group::getStudentsCount()const
{
	return _students_count;
}

bool Group::studentAskQuestion(const Student &student)
{
	for (int i = 0;i < _students_count;i++)
	{
		if (_students[i].getEGN() == student.getEGN())
		{
			return _mentor.helpStudent(_students[i]);
		}
	}
	return false;
}
