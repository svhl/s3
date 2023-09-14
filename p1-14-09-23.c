// create a student record consisting of roll no., name & marks of 5 subjects
// sort on the basis of total marks & display the mark list

#include <stdio.h>
#include <string.h>

struct Student
{
	int rno;
	char name[50];
	float m[5];
	float total;
};

void main()
{
	int n;
	printf("Enter no. of students:\n");
	scanf("%d", &n);
	struct Student s[n];

	for(int i = 0; i < n; i++)
	{
		printf("\nPerson %d:\n\n", i+1);
		printf("Enter roll no.:\n");
		scanf("%d", &s[i].rno);
		printf("Enter name:\n");
		scanf("%s", s[i].name);
		s[i].total = 0;

		for(int j = 0; j < 5; j++)
		{
			printf("Enter marks of subject %d:\n", j+1);
			scanf("%f", &s[i].m[j]);
			s[i].total += s[i].m[j];
		}
	}

	for(int i = 0; i < n; i++)
	{
		printf("\nPerson %d:\n\n", i+1);
		printf("Roll no.: %d\n", s[i].rno);
		printf("Name: %s\n", s[i].name);

		for(int j = 0; j < 5; j++)
		{
			printf("Marks of subject %d:\n", j+1);
			printf("%f\n", s[i].m[j]);
		}
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n-1-i; j++)
		{
			if(s[j].total < s[j+1].total)
			{
				struct Student temp = s[j];
				s[j] = s[j+1];
				s[j+1] = temp;
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		printf("\nRank %d\n", i+1);
		printf("Name: %s\n", s[i].name);
		printf("Total: %f\n", s[i].total);
	}
}
