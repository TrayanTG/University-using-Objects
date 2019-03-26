#pragma once
#include "lecturer.h"
#include "dean.h"

class Chancellor: public Lecturer
{
	char _university_name[64];
public:
	Chancellor();
	Chancellor(const Lecturer &lecturer, const char *universityName);

	const char *getUniversityName()const;

	bool hireDean(const Dean &hiredDean);
	bool fireDean(const Dean &firedDean);
};