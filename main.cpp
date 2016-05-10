#include <stdio.h>
#include <iostream>
#include "structures.h"
#include <string.h>
#define gsize 4

int writeToFile();
int readFromFile();
void inputGroup(int);
void inputStudent(Student*);
void inputStudents(Group *g);
void inputCurator(Group *g);
void mainMenu();
void createFile();
void appendGroup();

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
            //int n;
            //printf("Input number of groups\n");
            //scanf("%d",&n);
            //groups = new Group[n];
            readFromFile();
            break;
        case 3:
            return;
            break;
        default:
            printf("Input error\n");
            break;
        }
    }
}

int writeToFile()
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

int readFromFile()
{
	FILE *f;
	f = fopen("groups.bin","rb");
	if (fread(groups,sizeof(Group),sizeof(groups),f) == gsize)
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
    printf("Введите количество групп\n");
    //scanf("%d",&n);
    std::cin >> n;
    groups = new Group[n];
    for (int i = 0;i < n;i++)
        inputGroup(n);
    writeToFile();
    //delete [] groups;
}

void inputGroup(int n)//Input information about n-th group
{
    char name[7];
    printf("Input group name\n");
	gets(name);
	strcpy(groups[n].Name,name);
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
    gets(name);
    strcpy(stud->Fio.Name,name);
    printf("Input surname\n");
    gets(name);
    strcpy(stud->Fio.Surname,name);
    printf("Input middle name\n");
    gets(name);
    strcpy(stud->Fio.Middlename,name);
    printf("Input average mark\n");
    scanf("%f",&m);
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
    //TODO Birthday input
}

void editStudent(Group *g,int n)
{
    inputStudent(&g->Studs[n].S);
}

void appendGroup()
{
    //Placeholder
}
