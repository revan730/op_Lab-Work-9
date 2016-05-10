
enum Month {JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,NOV,OCT,DEC};
enum Form {BUDGET,CONTRACT};

struct FullName
{
	char Surname[20];
	char Name[20];
	char Middlename[20];
};

struct Teacher
{
	struct FullName Fio;
	Month Mon;
	unsigned short Day;
	unsigned short Year;
	char Position[20];
};

struct Student
{
	struct FullName	Fio;
	unsigned short Average;
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
};

