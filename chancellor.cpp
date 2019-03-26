#include "chancellor.h"

Chancellor::Chancellor()
{
	_university_name[0] = 0;
}

Chancellor::Chancellor(const Lecturer &lecturer, const char *universityName)
{
	setLecturer(lecturer);
	strcpy_s(_university_name, universityName);
}

const char *Chancellor::getUniversityName()const
{
	return _university_name;
}

bool Chancellor::hireDean(const Dean &hiredDean)
{
	//To be continued...
	return false;
}

bool Chancellor::fireDean(const Dean &firedDean)
{
	//To be continued...
	return false;
}