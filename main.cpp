#include <stdio.h>
#include <iostream>
#include "structures.h"
#include <string.h>
#define gsize 4
#include "first.h"

int writeToFile(int);
int readFromFile(int);
void inputGroup(int);
void inputStudent(Student*);
void inputStudents(Group *g);
void inputCurator(Group *g);
void mainMenu();
void tasksMenu(int);
void createFile();
void appendGroup();
void findLowest(Group*, int);

//struct Group groups[gsize];
struct Group *groups;

int main()
{
    mainMenu();
	return 0;
}

void mainMenu()
{
    while (true)
    {
        int i;
        printf("1.Create file\n2.Open file\n3.Close\n");
        scanf("%d",&i);
        switch(i)
        {
        case 1:
            createFile();
            break;
        case 2:
            int n;
            printf("Input number of groups\n");
            scanf("%d",&n);
            groups = new Group[n];
            readFromFile(n);
            tasksMenu(n);
            break;
        case 3:
            return;
        default:
            printf("Input error\n");
            break;
        }
    }
}

int writeToFile(int n)
{
	FILE *f;
	f = fopen("groups.bin","wb");
	if  (fwrite(groups,sizeof(Group),sizeof(groups),f) == gsize)
	{
		fclose(f);
		return 1;
	}
	fclose(f);
	return 0;
}

int readFromFile(int n)
{
	FILE *f;
	f = fopen("groups.bin","rb");
	if (fread(groups,sizeof(struct Group),n,f) == gsize)
	{
		fclose(f);
		return 1;
	}
	fclose(f);
	return 0;
}

void createFile()
{
    int n;
    printf("Input number of groups\n");
    //scanf("%d",&n);
    std::cin >> n;
    getchar();
    groups = new Group[n];
    for (int i = 0;i < n;i++)
        inputGroup(i);
    writeToFile(n);
    delete [] groups;
}

void inputGroup(int n)//Input information about n-th group
{
    char name[7];
    printf("Input group name:\n");
	gets(name);
	strcpy(groups[n].Name,name);
	strncpy(groups[n].Flow,groups[n].Name,2);
	printf("Input number of students\n");
	//scanf("%d",&groups[n].size);
	std::cin >> groups[n].size;
	inputStudents(&groups[n]);
	inputCurator(&groups[n]);
}

void inputStudents(Group *g)//Input students of specific group
{
    for (int i = 0;i < g->size;i++)
	{
	    inputStudent(&g->Studs[i].S);

	}
}

void inputStudent(Student *stud)//Input specific student's info
{
    char name[20];
    float m;
    int f;
    printf("Input student's name\n");
    getchar();
    gets(name);
    strcpy(stud->Fio.Name,name);
    printf("Input surname\n");
    gets(name);
    strcpy(stud->Fio.Surname,name);
    printf("Input middle name\n");
    gets(name);
    strcpy(stud->Fio.Middlename,name);
    printf("Input average mark\n");
    scanf("%f",&stud->Average);
    printf("0 - budget form (default),1 - contract form\n");
    //scanf("%d",&f);
    std::cin >> f;
    switch (f)
    {
        case 0:
            stud->F = BUDGET;
            break;
        case 1:
            stud->F = CONTRACT;
            break;
        default:
            stud->F = BUDGET;
            break;
    }
}

void inputCurator(Group *g)
{
	char name[20];
	printf("Input curator's name\n");
	getchar();
	gets(name);
	strcpy(g->Curator.T.Fio.Name,name);
	printf("Input surname\n");
    gets(name);
    strcpy(g->Curator.T.Fio.Surname,name);
    printf("Input middle name\n");
    gets(name);
    strcpy(g->Curator.T.Fio.Middlename,name);
    printf("Input curator's position\n");
    gets(name);
    strcpy(g->Curator.T.Position,name);
    printf("Input date of birth (DD MM YYYY)\n");
    scanf("%2d %2d %4d",&g->Curator.T.Day,&g->Curator.T.Mon,&g->Curator.T.Year);
}

void editStudent(Group *g,int n)
{
    inputStudent(&g->Studs[n].S);
}

void tasksMenu(int n)
{
    while (true)
    {
        int c;
        printf("1.Find student's with lowest mark\n");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
            findLowest(groups,n);
        }
    }
}
void appendGroup()
{
    /*Group g;
    FILE *f;
    f = fopen("groups.bin","ab");
    fseek()
    fwrite(groups,sizeof(Group),sizeof(groups),f)
    */
}
