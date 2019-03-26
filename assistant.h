#pragma once
#include "student.h"
#include "lecturer.h"
#include "group.h"

class Lecturer;

class Assistant: public Person
{
	SubjectsList	 _subject;
	const Lecturer	 *_lecturer;
	const Group		 *_group;
public:
	Assistant();
	Assistant(const Person &person, SubjectsList subject, const Lecturer *lecturer, const Group *group);
	
	SubjectsList getSubject()const;
	Lecturer getLecturer()const;
	Group getGroup()const;

	bool setLecturer(const Lecturer *lecturer);

	void tutor();
	void prepareLesson();
	void reachLecturer(const Student &askingStudent);
	bool setMark(float mark, const Student &examinedStudent);

};