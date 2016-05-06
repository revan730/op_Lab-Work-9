#include <stdio.h>
#include "structures.h"
#include <string.h>
#define gsize 4

int writeToFile();
int readFromFile();

struct Group[gsize] groups;

int main()
{
	return 0;
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

void inputGroup(int n)//Input information about n-th group
{
	printf("Input number of students\n");
	scanf("%d",&groups[n].size);
	inputStudents(&groups[n]);
	inputCurator(&groups[n];)
}

void inputStudents(Group *g)
{
    for (int i = 0;i < g.size;i++)
	{
		char[20] name;
		float m;
		int f;
		printf("Input %d-nt's student name\n",i + 1);
		gets(name);
		strcpy(g.Studs[i].S.Name,name);
		printf("Input surname\n");
		gets(name);
		strcpy(g.Studs[i].S.Surname,name);
		printf("Input middle name\n");
		gets(name);
		strcpy(g.Studs[i].S.Middlename,name);
		printf("Input average mark\n");
		scanf("%f",&m);
		printf("0 - budget form (default),1 - contract form");
		scanf("%d",&f);
		switch (f)
		{
        case 0:
            g.Studs[i].S.F = BUDGET;
            break;
        case 1:
            g.Studs[i].S.F = CONTRACT;
            break;
        default:
            g.Studs[i].S.F = BUDGET;
            break;
		}
	}
}

void inputCurator(Group *g)
{
    char[20] name;
    printf("Input curator's name\n");
    gets(name);
    strcpy(g.Curator.T.Name,name);
    printf("Input surname\n");
    gets(name);
    strcpy(g.Curator.T.Surname,name);
    printf("Input middle name\n");
    gets(name);
    strcpy(g.Curator.T.Middlename,name);
    printf("Input curator's position");
    gets(name);
    strcpy(g.Curator.T.Position,name);
    //TODO Birthday input
}
