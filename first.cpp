#include "first.h"

void findLowest(Group* g,int n)
{
    for (int i = 0;i < n;i++)
    {
        Student* min;
        min = &g[i].Studs[0].S;
        for (int j = 1;j < g[i].size;j++)
        {
            if (g[i].Studs[j].S.Average < min->Average)
                min = &g[i].Studs[j].S;
        }
        printf("Student with min mark - %s %s\nMark - %f\nGroup %s\nCurator - %s %s\n",min->Fio.Name,min->Fio.Surname,min->Average,g[i].Name,g[i].Curator.T.Fio.Name,g[i].Curator.T.Fio.Surname);
    }
}
