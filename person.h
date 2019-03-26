#pragma once

class Person
{
	char   _name[64];
	char   _EGN[11];
	double _knowledge;
public:
	Person();
	Person(const char *name, const char *EGN, double knowledge);
	void setPerson(const Person& person);
	const char *getName()const;
	const char *getEGN()const;
	double getKnowledge()const;
	bool increaseKnowledge(double teacherKnowledge, double ratio=0.1);
};