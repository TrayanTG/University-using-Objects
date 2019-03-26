#include<iostream>
#include "student.h"

Student::Student(): _faculty(Undefined_Faculty), _major(Undefined_Major), _semester(0), _administrative_group(0), _subjects_count(0)
{
	_fn[0] = 0;
	_subjects[0] = Undefined_Subject;
}

Student::Student(const Person &person, const char *fn, FacultiesList faculty, const SubjectsList *subjectList, MajorsList major
			   , char semester, char administrativeGroup, char subjectsCount)
{
	setPerson(person);
	strcpy_s(_fn, fn);
	_faculty = faculty;
	for (_subjects_count = 0;_subjects_count < subjectsCount;_subjects_count++)
	{
		_subjects[_subjects_count] = subjectList[_subjects_count];
	}
	_major = major;
	_semester = semester;
	_administrative_group = administrativeGroup;
}

const char *Student::getFN()const
{
	return _fn;
}

FacultiesList Student::getFaculty()const
{
	return _faculty;
}

const SubjectsList *Student::getSubjectsList()const
{
	return _subjects;
}

MajorsList Student::getMajor()const
{
	return _major;
}

float Student::getMark(SubjectsList subject)const
{
	for (int i = 0;i < _subjects_count;i++)
	{
		if (_subjects[i] == subject)
		{
			return _marks[i].getAvg();
		}
	}
	return -1;
}

char Student::getSemester()const
{
	return _semester;
}

char Student::getAdministrativeGroup()const
{
	return _administrative_group;
}

char Student::getSubjectsCount()const
{
	return _subjects_count;
}


bool Student::changeFaculty(FacultiesList newFaculty)
{
	if (_faculty == newFaculty)
	{
		return false;
	}
	_faculty = newFaculty;
	return true;
}

bool Student::addSubject(SubjectsList newSubject)
{
	for (int i = 0;i < _subjects_count;i++)
	{
		if (_subjects[i] == newSubject)
		{
			return false;
		}
	}
	_subjects[_subjects_count] = newSubject;
	_marks[_subjects_count++].reset();
	return true;
}

bool Student::removeSubject(SubjectsList removedSubject)
{
	for (int i = 0;i < _subjects_count;i++)
	{
		if (_subjects[i] == removedSubject)
		{
			for (int j = i;j < _subjects_count - 1;j++)
			{
				_marks[j] = _marks[j+1];
				_subjects[j] = _subjects[j + 1];
			}
			_subjects_count--;
			return true;
		}
	}
	return false;
}

bool Student::changeMajor(MajorsList newMajor)
{
	if (_major == newMajor)
	{
		return false;
	}
	_major = newMajor;
	return true;
}

bool Student::getMark(float mark, SubjectsList subject)
{
	for (int i = 0;i < _subjects_count;i++)
	{
		if (_subjects[i] == subject)
		{
			return _marks[i].addMark(mark);
		}
	}
	return false;
}

void Student::increaseSemester()
{
	/// A lot of things should change such as resseting mark, subjects, etc.
	increaseKnowledge(2*getKnowledge(), 0.1);
	_semester++;
}

bool Student::changeAdministrativeGroup(char newAdministrativeGroup)
{
	if (newAdministrativeGroup > MAX_GROUP_COUNT || _administrative_group == newAdministrativeGroup)
	{
		return false;
	}
	_administrative_group = newAdministrativeGroup;
	return true;
}

void Student::savePenguins()
{
	// A true master of mind knows the importance of penguins...
	increaseKnowledge(2 * getKnowledge(), 1);
}