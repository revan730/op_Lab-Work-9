#ifndef STRUCT_H
#define STRUCT_H


enum Month {JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,NOV,OCT,DEC};
enum Form {DAY,ZAO};
enum Pos {DOC,AST,PROF};

struct FullName
{
	char Surname[20];
	char Name[20];
	char Middlename[20];
};

struct Teacher
{
	struct FullName Fio;
	unsigned short Mon;
	unsigned short Day;
	unsigned short Year;
	Pos Position;
};

struct Student
{
	struct FullName	Fio;
	float Average;
	Form F;
};

union Person
{
	struct Student S;
	struct Teacher T;
};

struct Group
{
	union Person Studs[40];
	union Person Curator;
	unsigned short size;
	char Name[6];
	char Flow[3];
	unsigned short Course;
};

#endif // STRUCT_H
