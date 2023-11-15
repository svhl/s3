// THIS PROGRAM ISN'T PART OF LAB CYCLE
// create a student record consisting of roll no., name & marks of 5 subjects
// sort on the basis of total marks & display the mark list

#include <stdio.h>
#include <string.h>

struct Student
{
	int rno;
	char name[50];
	float marks[5];
	float total;
};

void main()
{
	int n, i, j;
	printf("Enter no. of students:\n");
	scanf("%d", &n);
	struct Student s[n];

	for(i = 0; i < n; i++)
	{
		printf("\nPerson %d:\n\n", i+1);
		printf("Enter roll no.:\n");
		scanf("%d", &s[i].rno);
		printf("Enter name:\n");
		scanf("%s", s[i].name);
		s[i].total = 0;

		for(j = 0; j < 5; j++)
		{
			printf("Enter marks of subject %d:\n", j+1);
			scanf("%f", &s[i].marks[j]);
			s[i].total += s[i].marks[j];
		}
	}

	for(i = 0; i < n; i++)
	{
		printf("\nPerson %d:\n\n", i+1);
		printf("Roll no.: %d\n", s[i].rno);
		printf("Name: %s\n", s[i].name);

		for(j = 0; j < 5; j++)
		{
			printf("Marks of subject %d:\n", j+1);
			printf("%f\n", s[i].marks[j]);
		}
	}

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n-1-i; j++)
		{
			if(s[j].total < s[j+1].total)
			{
				struct Student temp = s[j];
				s[j] = s[j+1];
				s[j+1] = temp;
			}
		}
	}
	
	for(i = 0; i < n; i++)
	{
		printf("\nRank %d\n", i+1);
		printf("Name: %s\n", s[i].name);
		printf("Total: %f\n", s[i].total);
	}
}
