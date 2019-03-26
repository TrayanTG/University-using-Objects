#include "mark.h"

Mark::Mark() : count(0) { memset(mark, 0, sizeof(mark)); }

float Mark::getAvg()const
{
	float temp = 0;
	for (int i = 0;i < count;i++)
	{
		temp = mark[i];
	}
	return temp / count;
}

void Mark::reset()
{
	memset(mark, 0, sizeof(mark));
}

bool Mark::addMark(float newMark)
{
	if (count >= 15)
	{
		return false;
	}
	mark[count++] = newMark;
	return true;
}
