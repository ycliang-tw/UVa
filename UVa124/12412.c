#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#define EPS 1.0E-6

enum DQ {delete = 0, query};
enum subject {chin = 0, math, eng, prog};
enum status {passed = 0, failed, total};

struct Student{
	char sid[15];
	char name[15];
	int cid;
	int scores[4];
	int passed;
	int total;
	float ave;
} student[200];

int sidx = 0;
int choice;

char *prompt[6] = {" ",
				   "Please enter the SID, CID, name and four scores. Enter 0 to finish.\n",
				   "Please enter SID or name. Enter 0 to finish.\n",
				   "Please enter SID or name. Enter 0 to finish.\n",
				   "Showing the ranklist hurts students' self-esteem. Don't do that.\n",
				   "Please enter class ID, 0 for the whole statistics.\n"};

void menu()
{
	printf("Welcome to Student Performance Management System (SPMS).\n\n"
			"1 - Add\n"
			"2 - Remove\n"
			"3 - Query\n"
			"4 - Show ranking\n"
			"5 - Show Statistics\n"
			"0 - Exit\n\n");
}

void add()
{
	for(;;){
		char sid[15] = {}, name[15] = {};
		int scores[4] = {}, cid = 0, i = 0, flag = 1;
		
		/* read in */
		printf("%s", prompt[choice]);
		scanf("%s", sid);
		if(strcmp(sid, "0") == 0)	break;
		scanf("%d%s%d%d%d%d", &cid, name, &scores[chin], &scores[math], &scores[eng], &scores[prog]);
		
		/* duplicated */
		for(i = 0; i < sidx; i++){
			if(strcmp(sid, student[i].sid) == 0){
				printf("Duplicated SID.\n");
				flag = 0;
			}
		}
		if(i != sidx || flag == 0)	continue;

		/* assign */
		strcpy(student[sidx].sid, sid);
		strcpy(student[sidx].name, name);
		student[sidx].scores[chin] = scores[chin];
		student[sidx].scores[math] = scores[math];
		student[sidx].scores[eng] = scores[eng];
		student[sidx].scores[prog] = scores[prog];
		student[sidx].cid = cid;
		student[sidx].total = scores[chin]+scores[math]+scores[eng]+scores[prog];
		student[sidx].ave = (float)student[sidx].total/4.0 + EPS;
		student[sidx].passed = (scores[chin]>=60) + (scores[math]>=60) + (scores[eng]>=60) + (scores[prog]>=60);
		sidx++;
	}
}

int ranking(int id)
{
	int rank = sidx;
	int total = student[id].total, i;
	for(i = 0; i < sidx; i++){
		if(total >= student[i].total){
			rank--;
		}
	}
	return rank+1;
}

void del_query(int flag)
{
	for(;;){
		char input[15] = {};
		printf("%s", prompt[choice]);
		scanf("%s", input);
		if(strcmp(input, "0") == 0)	break;

		int num = 0, i;
		for(i = 0; i < sidx; i++){
			if(strcmp(student[i].name, input) == 0 || strcmp(student[i].sid, input) == 0){
				if(flag == delete){
					memmove(&student[i], &student[i+1], sizeof(struct Student)*(sidx-i-1));
					i = -1;
					sidx--;
					num++;
				}else if(flag == query){
					printf("%d %s %d %s %d %d %d %d %d %.2f\n", ranking(i), student[i].sid, student[i].cid, student[i].name, student[i].scores[chin], student[i].scores[math], student[i].scores[eng], student[i].scores[prog], student[i].total, student[i].ave);
				}
			}
		}
		if(flag == delete)	printf("%d student(s) removed.\n", num);
	}
}

void add_up(int stats[][3], const struct Student *a, int *pass)
{
	if(a->scores[chin] >= 60)	stats[chin][passed]++;
	if(a->scores[math] >= 60)	stats[math][passed]++;
	if(a->scores[eng] >= 60)	stats[eng][passed]++;
	if(a->scores[prog] >= 60)	stats[prog][passed]++;
	if(a->scores[chin] < 60)	stats[chin][failed]++;
	if(a->scores[math] < 60)	stats[math][failed]++;
	if(a->scores[eng] < 60)		stats[eng][failed]++;
	if(a->scores[prog] < 60)	stats[prog][failed]++;
	pass[a->passed]++;
	stats[chin][total] += a->scores[chin];
	stats[math][total] += a->scores[math];
	stats[eng][total] += a->scores[eng];
	stats[prog][total] += a->scores[prog];
}

void print_stats(int stats[][3], int num, int *pass)
{
	pass[3] += pass[4];
	pass[2] += pass[3];
	pass[1] += pass[2];
	printf("Chinese\n"
		   "Average Score: %.2f\n"
		   "Number of passed students: %d\n"
		   "Number of failed students: %d\n\n"

		   "Mathematics\n"
		   "Average Score: %.2f\n"
		   "Number of passed students: %d\n"
		   "Number of failed students: %d\n\n"

		   "English\n"
		   "Average Score: %.2f\n"
		   "Number of passed students: %d\n"
		   "Number of failed students: %d\n\n"

		   "Programming\n"
		   "Average Score: %.2f\n"
		   "Number of passed students: %d\n"
		   "Number of failed students: %d\n\n"

		   "Overall:\n"
		   "Number of students who passed all subjects: %d\n"
		   "Number of students who passed 3 or more subjects: %d\n"
		   "Number of students who passed 2 or more subjects: %d\n"
		   "Number of students who passed 1 or more subjects: %d\n"
		   "Number of students who failed all subjects: %d\n\n",
		   (num!=0)?(float)stats[chin][total] / (float)num + EPS:0.00, stats[chin][passed], stats[chin][failed],
		   (num!=0)?(float)stats[math][total] / (float)num + EPS:0.00, stats[math][passed], stats[math][failed],
		   (num!=0)?(float)stats[eng][total] / (float)num + EPS:0.00, stats[eng][passed], stats[eng][failed],
		   (num!=0)?(float)stats[prog][total] / (float)num + EPS:0.00, stats[prog][passed], stats[prog][failed],
		   pass[4], pass[3], pass[2], pass[1], pass[0]);
}

void stat()
{
	int cid = 0;
	printf("%s", prompt[choice]);
	scanf("%d", &cid);

	int stats[4][3] = {};
	int num = 0;
	int pass[5] = {}, i;

	for(i = 0; i < sidx; i++){
		struct Student *tmp = &student[i];
		if(cid != 0){
			if(tmp->cid == cid){
				add_up(stats, tmp, pass);
				num++;
			}
			
		}else{
			add_up(stats, tmp, pass);
			num++;
		}
	}

	print_stats(stats, num, pass);
}

int main()
{	
	while(1){
		menu();
		scanf("%d", &choice);
		if(choice == 0)	break;
		if(choice == 1)	add();
		if(choice == 2)	del_query(delete);
		if(choice == 3)	del_query(query);
		if(choice == 4)	printf("%s", prompt[choice]);
		if(choice == 5)	stat();
	}
	return 0;
}
