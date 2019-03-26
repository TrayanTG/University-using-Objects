#include "mentor.h"

Mentor::Mentor()
{

}

bool Mentor::helpStudent(Student &student)
{
	return student.increaseKnowledge(getKnowledge());
}