#include<iostream>
#include<cstring>

#include "person.h"


Person::Person(): _knowledge(0)
{
	_name[0] = 0;
	_EGN[0] = 0;
}

Person::Person(const char *name, const char *EGN, double knowledge) : _knowledge(knowledge)
{
	memcpy(_EGN, EGN, 11);
	strcpy_s(_name, name);
}

void Person::setPerson(const Person& person)
{
	strcpy_s(_name, person.getName());
	strcpy_s(_EGN, person.getEGN());
	_knowledge = person.getKnowledge();
}

const char *Person::getName()const
{
	return _name;
}

const char *Person::getEGN()const
{
	return _EGN;
}

double Person::getKnowledge()const
{
	return _knowledge;
}

bool Person::increaseKnowledge(double teacherKnowledge, double ratio)
{
	if (_knowledge >= teacherKnowledge)
	{
		return false;
	}
	_knowledge += ratio*(teacherKnowledge - _knowledge);
	return true;
}
