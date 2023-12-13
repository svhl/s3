// write a program to read a sentence & reverse each word in it

import java.util.*;

class reverse
{
	public static void main(String[] args)
	{
		String s1, s2 = "", token, word;
		int i;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter a sentence:");
		s1 = sc.nextLine();
		StringTokenizer tokenizer = new StringTokenizer(s1);

		while(tokenizer.hasMoreTokens())
		{
			token = tokenizer.nextToken();
			word = "";

			for(i = 0; i < token.length(); i++)
			{
				word = token.charAt(i) + word;
			}

			s2 = s2 + word + " ";
		}

		System.out.println("Sentence with every word reversed:\n" + s2);
	}
}
