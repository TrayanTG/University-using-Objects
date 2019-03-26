#pragma once
#include "assistant.h"
#include "student.h"
#include "group.h"
#include "constantsData.h"

class Assistant;

class Lecturer: public Person
{
	const char		*_title;
	SubjectsList 	 _subject;
	const Group		*_group;
	const Assistant	*_assistants[MAX_ASSISTANTS_COUNT];
	char			 _assistants_count;
public:
	Lecturer();
	Lecturer(const Person &person, const char *title, SubjectsList subject, const Group *group);

	void setLecturer(const Lecturer &lecturer);

	const char *getTitle()const;
	SubjectsList getSubject()const;
	Group getGroup()const;
	const Assistant *getAssistant()const;
	char getAssistantsCount()const;

	bool hireAssistant(const Assistant *hiredAssistant);
	bool fireAssistant(const Assistant *firedAssistant);

	void tutor();
	void prepareLesson();
	bool setMark(float mark, const Student &examinedStudent);

};