// write a program to read a sentence & capitalize each word

import java.util.*;

class capitalize
{
	public static void main(String[] args)
	{
		String s1, s2 = "", token;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter a sentence:");
		s1 = sc.nextLine();
		StringTokenizer tokenizer = new StringTokenizer(s1);

		while(tokenizer.hasMoreTokens())
		{
			token = tokenizer.nextToken();
			s2 = s2 + (token.toUpperCase()).charAt(0) + token.substring(1) + " ";
		}

		System.out.println("New sentence:\n" + s2);
	}
}
