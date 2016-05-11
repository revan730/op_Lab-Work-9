#include "third.h"

void findRecommended(Group *g,int n)
{
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < g[i].size;j++)
        {
            if (g[i].Studs[j].S.Average >= 4.0 && g[i].Course == 4)
            writeToFile(&g[i].Studs[j].S);
        }
    }
}
int writeToFile(Student *S)
{
    FILE *f;
    f = fopen("magistr.bin","ab");
    fseek(f,0,SEEK_END);
    fwrite(S,sizeof(Student),1,f);
    fclose(f);
    return 1;
}
