// write a java program that takes an integer as input & reverses digits using for loop

import java.util.Scanner;
public class reverse
{
	public static void main(String[] args)
	{
		int n1, n2 = 0;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter a no.:");
		n1 = sc.nextInt();

		for(; n1 != 0; n1 /= 10)
		{
			n2 = n2 * 10 + (n1 % 10);
		}

		System.out.println("Reversed no.: " + n2);
	}
}