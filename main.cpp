#include <stdio.h>
#include <iostream>
#include "structures.h"
#include <string.h>
#define gsize 5
#include "first.h"
#include "second.h"
#include "third.h"

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
void findRecommended(Group *g,int n);
int writeToFile(Student *S);
void printTeachersToLeave(Group * groups, int gQuan);

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

void appendGroup() {
	FILE *f;
	f = fopen("groups.bin","r+b");
	int gQuan;
	fread(&gQuan, sizeof(int), 1, f);
	gQuan++;
	fseek(f, 0, SEEK_SET);
	fwrite(&gQuan, sizeof(int), 1, f);

	Group g;

    char name[7];
    printf("Input group name:\n");
	gets(name);
	strcpy(g.Name,name);
	strncpy(g.Flow,g.Name,2);
    char c = g.Name[3];
	g.Course = 6 - atoi(&c);
	printf("Input number of students\n");
	//scanf("%d",&groups[n].size);
	std::cin >> g.size;
	inputStudents(&g);
	inputCurator(&g);

	fseek(f, sizeof(Group)*(gQuan - 1), SEEK_CUR);
	fwrite(&g, sizeof(Group), 1, f);

	fclose(f);
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
    char c = groups[n].Name[3];
	groups[n].Course = 6 - atoi(&c);
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
    printf("0 - daily form (default),1 - absentia form\n");
    //scanf("%d",&f);
    std::cin >> f;
    switch (f)
    {
        case 0:
            stud->F = DAY;
            break;
        case 1:
            stud->F = ZAO;
            break;
        default:
            stud->F = DAY;
            break;
    }
}

void inputCurator(Group *g)
{
    char name[20];
	int p;
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
    printf("Select position:0 - docent,1 - assistant,2 - professor\n");
    scanf("%d",&p);
    getchar();
        switch (p)
    {
        case 0:
            g->Curator.T.Position = DOC;
            break;
        case 1:
            g->Curator.T.Position = AST;
            break;
        case 2:
            g->Curator.T.Position = PROF;
            break;
        default:
            g->Curator.T.Position = DOC;
            break;

    }
    printf("Input date of birth (DD MM YYYY)\n");
    scanf("%d %d %4d",&g->Curator.T.Day,&g->Curator.T.Mon,&g->Curator.T.Year);

    getchar();
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
        printf("1.Find student's with lowest mark\n2.Old teachers\n3.Recommended for magistry\n");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
            findLowest(groups,n);
            break;
        case 2:
            printTeachersToLeave(groups,n);
            break;
        case 3:
            findRecommended(groups,n);
            break;
        }
    }
}
