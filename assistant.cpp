#include "assistant.h"

Assistant::Assistant(): _subject(Undefined_Subject), _lecturer(nullptr)
{

}

Assistant::Assistant(const Person &person, SubjectsList subject, const Lecturer *lecturer, const Group *group)
{
	setPerson(person);
	_subject = subject;
	_lecturer = lecturer;
	_group = group;
}

SubjectsList Assistant::getSubject()const
{
	return _subject;
}

Lecturer Assistant::getLecturer()const
{
	return *_lecturer;
}

Group Assistant::getGroup()const
{
	return *_group;
}

bool Assistant::setLecturer(const Lecturer *lecturer)
{
	if (_lecturer->getEGN() == lecturer->getEGN())
	{
		return false;
	}
	_lecturer = lecturer;
	return true;
}

void Assistant::tutor()
{
	for (int i = 0;i < _group->getStudentsCount();i++)
	{
		_group->getStudents()[i].increaseKnowledge(getKnowledge(),0.1);
	}
}

void Assistant::prepareLesson()
{
	increaseKnowledge(getKnowledge(), 0.005);
}

void Assistant::reachLecturer(const Student &askingStudent)
{
	/// Comming soon...
}

bool Assistant::setMark(float mark, const Student &examinedStudent)
{
	for (int i = 0;i < _group->getStudentsCount();i++)
	{
		if (examinedStudent.getEGN() == _group->getStudents()[i].getEGN())
		{
			return _group->getStudents()[i].getMark(mark, _subject);
		}
	}
	return false;
}