#pragma once
#include<iostream>

struct Mark
{
	float mark[16];
	char  count;
	Mark();
	float getAvg()const;
	void reset();
	bool addMark(float newMark);
};