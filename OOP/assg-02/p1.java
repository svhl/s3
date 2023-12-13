// write a program to read a sentence & count the vowels & consonants

import java.util.*;

class count
{
	public static void main(String[] args)
	{
		String s1, s2, vs = "aeiou", cs = "bcdfghjklmnpqrstvwxyz";
		int i, v = 0, c = 0;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter a sentence:");
		s1 = sc.nextLine();
		s2 = s1.toLowerCase();

		for(i = 0; i < s2.length(); i++)
		{
			if(vs.indexOf(s2.charAt(i)) != -1)
			{
				v++;
			}

			else if(cs.indexOf(s2.charAt(i)) != -1)
			{
				c++;
			}
		}

		System.out.println("No. of vowels: " + v);
		System.out.println("No. of consonants: " + c);
	}
}
