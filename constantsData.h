#pragma once

enum SubjectsList { Undefined_Subject , Linear_Algebra, UP, OOP };
enum MajorsList { Undefined_Major , Informatics, Computer_Science, Software_Engineering };
enum FacultiesList { Undefined_Faculty , FMI, FHF };

const int MAX_TITLE_LENGHT = 32;
const int MAX_GROUP_COUNT = 6;
const int MAX_GROUP_SOZE = 25;
const int MAX_ASSISTANTS_COUNT = 6;

const char TITLES[3][MAX_TITLE_LENGHT] = { "Main Assistant", "Dean", "Professor" };
