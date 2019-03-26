#pragma once
#include "person.h"
#include "mark.h"
#include "constantsData.h"

class Student : public Person
{
	char			_fn[8];
	FacultiesList	_faculty;
	SubjectsList	_subjects[8];
	MajorsList		_major;
	Mark			_marks[8];
	char			_semester;
	char			_administrative_group;
	char			_subjects_count;
public:
	Student();
	Student(const Person &person, const char *fn, FacultiesList faculty, const SubjectsList *subjectList, MajorsList major
	      , char semester, char administrativeGroup, char subjectsCount);

	const char *getFN()const;
	FacultiesList getFaculty()const;
	const SubjectsList *getSubjectsList()const;
	MajorsList getMajor()const;
	char getSemester()const;
	char getAdministrativeGroup()const;
	char getSubjectsCount()const;
	float getMark(SubjectsList subject)const;

	bool changeFaculty(FacultiesList newFaculty);
	bool addSubject(SubjectsList newSubject);
	bool removeSubject(SubjectsList removedSubject);
	bool changeMajor(MajorsList newMajor);
	bool getMark(float mark, SubjectsList subject);
	void increaseSemester();
	bool changeAdministrativeGroup(char newAdministrativeGroup);
	void savePenguins();
};