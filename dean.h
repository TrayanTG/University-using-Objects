#pragma once
#include "lecturer.h"

class Dean : public Lecturer
{
	FacultiesList _faculty;
public:
	Dean();
	Dean(const Lecturer &lecturer, FacultiesList faculty);

	FacultiesList getFaculty()const;

	bool hireLecturer(const Lecturer &hiredLecturer);
	bool fireLecturer(const Lecturer &firedLecturer);
};
