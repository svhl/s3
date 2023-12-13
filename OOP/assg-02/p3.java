// write a program to read a sentence & print the longest word in it & check whether it's a palindrome

import java.util.*;

class longest
{
	public static void main(String[] args)
	{
		String s1, token, longest = "";
		int i, j;
		boolean f = true;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter a sentence:");
		s1 = sc.nextLine();
		StringTokenizer tokenizer = new StringTokenizer(s1);

		while(tokenizer.hasMoreTokens())
		{
			token = tokenizer.nextToken();

			if(token.length() > longest.length())
			{
				longest = token;
			}
		}

		j = longest.length() - 1;

		for(i = 0; i < longest.length() / 2; i++)
		{
			if((longest.toLowerCase()).charAt(i) != (longest.toLowerCase()).charAt(j))
			{
				f = false;
			}

			j--;
		}

		System.out.println("Longest word:\n" + longest);

		if(f)
		{
			System.out.println("Longest word is a palindrome");
		}

		else
		{
			System.out.println("Longest word isn't a palindrome");
		}
	}
}
