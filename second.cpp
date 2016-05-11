#include "structures.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using namespace std;

void printTeacherInfo(Teacher * t);

void printTeachersToLeave(Group * groups, int gQuan) {
	if (groups == NULL || groups == nullptr)
		return;
	Teacher ** teachers = new Teacher * [gQuan];

	for (int i = 0; i < gQuan; i++)
		teachers[i] = nullptr;
	int howMuchTeachers = 0;
	for (int i = 0; i < gQuan; i++) {
		if (strcmp(groups[i].Curator.T.Position, "доцент") == 0 && (2016 - groups[i].Curator.T.Year) > 60 ) {
			teachers[howMuchTeachers] = &groups[i].Curator.T;
			teachers++;
		}
	}

 for (int i = 0; i < howMuchTeachers-1; i++) {
	 bool swapped = false;
	 for (int j = 0; j < howMuchTeachers-i-1; j++) {
		if (strcmp(teachers[j]->Fio.Surname, teachers[j+1]->Fio.Surname) > 0) {
			Teacher * b = teachers[j];
			teachers[j] = teachers[j+1];
			teachers[j+1] = b;
			swapped = true;
		}
	 }
	 for(int i = 0; i < howMuchTeachers; i++) {
		 printTeacherInfo(teachers[i]);
	 }
	 if(!swapped)
		break;
 }

}

void printTeacherInfo(Teacher * t) {
	printf("%s %s %s (%d %d %d)\n", t->Fio.Surname, t->Fio.Name, t->Fio.Middlename, t->Year, t->Mon, t->Day);
}

