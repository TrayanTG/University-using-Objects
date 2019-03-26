#include "lecturer.h"

Lecturer::Lecturer() : _title(nullptr), _subject(Undefined_Subject), _group(nullptr), _assistants_count(0)
{

}

Lecturer::Lecturer(const Person &person, const char *title, SubjectsList subject, const Group *group) : _assistants_count(0)
{
	setPerson(person);
	_title = title;
	_subject = subject;
	_group = group;
}

void Lecturer::setLecturer(const Lecturer &lecturer)
{
	setPerson({ lecturer.getName(),lecturer.getEGN(),lecturer.getKnowledge() });
	_title = lecturer.getTitle();
	_subject = lecturer.getSubject();
	_group = lecturer._group;
}

const char *Lecturer::getTitle()const
{
	return _title;
}

SubjectsList Lecturer::getSubject()const
{
	return _subject;
}

Group Lecturer::getGroup()const
{
	return *_group;
}

const Assistant * Lecturer::getAssistant()const
{
	return *_assistants;
}

char Lecturer::getAssistantsCount()const
{
	return _assistants_count;
}

bool Lecturer::hireAssistant(const Assistant *hiredAssistant)
{
	if (_assistants_count >= MAX_ASSISTANTS_COUNT)return false;
	for (int i = 0;i < _assistants_count;i++)
	{
		if (_assistants[i]->getEGN() == hiredAssistant->getEGN())
		{
			return false;
		}
	}
	_assistants[_assistants_count++] = hiredAssistant;
	return true;
}

bool Lecturer::fireAssistant(const Assistant *firedAssistant)
{
	for (int i = 0;i < _assistants_count;i++)
	{
		if (_assistants[i]->getEGN() == firedAssistant->getEGN())
		{
			for (int j = i + 1;j < _assistants_count;j++)
			{
				_assistants[j - 1] = _assistants[j];
			}
			_assistants_count--;
			return true;
		}
	}
	return false;
}

void Lecturer::tutor()
{
	for (int i = 0;i < _assistants_count;i++)
	{
		for (int j = 0;j < _assistants[i]->getGroup().getStudentsCount();j++)
		{
			_assistants[i]->getGroup().getStudents()[j].increaseKnowledge(getKnowledge(), 0.1);
		}
	}
}

void Lecturer::prepareLesson()
{
	increaseKnowledge(getKnowledge(), 0.005);
}

bool Lecturer::setMark(float mark, const Student &examinedStudent)
{
	for (int i = 0;i < _assistants_count;i++)
	{
		for (int j = 0;j < _assistants[i]->getGroup().getStudentsCount();j++)
		{
			if (_assistants[i]->getGroup().getStudents()[j].getEGN() == examinedStudent.getEGN())
			{
				return _assistants[i]->getGroup().getStudents()[j].getMark(mark, _subject);
			}
		}
	}
	return false;
}