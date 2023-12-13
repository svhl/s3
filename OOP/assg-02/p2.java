// write a program to read a sentence & count the no. of words that end with vowels

import java.util.*;

class count
{
	public static void main(String[] args)
	{
		String s1, s2, token, vs = "aeiou";
		int v = 0;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter a sentence:");
		s1 = sc.nextLine();
		s2 = s1.toLowerCase();
		StringTokenizer tokenizer = new StringTokenizer(s2);

		while(tokenizer.hasMoreTokens())
		{
			token = tokenizer.nextToken();

			if(vs.indexOf(token.charAt(token.length()-1)) != -1)
			{
				v++;
			}
		}

		System.out.println("No. of words ending with vowels: " + v);
	}
}
