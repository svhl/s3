// develop a java program that takes student's score as input & prints their corresponding grade
// use and else-if ladder to define grading criteria

import java.util.Scanner;
public class grade
{
	public static void main(String[] args)
	{
		float score;
		char grade;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter score:");
		score = sc.nextFloat();
		
		if(score > 100 || score < 0)
		{
			System.out.println("Enter score between 0-100");
			return;
		}
		
		else if(score >= 90)
		{
			grade = 'A';
		}

		else if(score >= 80)
		{
			grade = 'B';
		}

		else if(score >= 70)
		{
			grade = 'C';
		}
		
		else if(score >= 60)
		{
			grade = 'D';
		}

		else
		{
			grade = 'E';
		}

		System.out.println("Grade: " + grade);
	}
}