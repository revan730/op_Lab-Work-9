
enum Month {JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,NOV,OCT,DEC};
enum Form {BUDGET,CONTRACT};

struct FullName
{
	char[20] Surname;
	char[20] Name;
	char[20] Middlename;
}

struct Teacher
{
	struct FullName Fio;
	Month Mon;
	unsigned short Day;
	unsigned short Year;
	char[20] Position;
}

struct Student
{
	struct FullName	Fio;
	unsigned short Average;
	Form F;
}

union Person
{
	struct Student;
	struct Teacher;
}

struct Group
{
	union[40] Person Studs;
	union Person Curator;
	unsigned short size;
	char[6] Name;
}

