// design a menu driven calculator program in java using a do-while loop
// program should display a menu w/ options for addition, subtraction, multiplication & division
// it should keep executing until the user chooses to exit

import java.util.Scanner;
class calculator
{
	public static void main(String[] args)
	{
		boolean cont = true;
		float ch, a = 0, b = 0;
		Scanner sc = new Scanner(System.in);

		while(cont == true)
		{
			System.out.println("Menu");
			System.out.println("1. Addition");
			System.out.println("2. Subtraction");
			System.out.println("3. Multiplication");
			System.out.println("4. Division");
			System.out.println("Any other choice to exit");
			System.out.println("Enter choice:");
			ch = sc.nextInt();

			if(ch == 1 || ch == 2 || ch == 3 || ch == 4)
			{
				System.out.println("\nEnter 2 no.s:");
				a = sc.nextFloat();
				b = sc.nextFloat();
			}

			if(ch == 1)
			{
				System.out.println("Sum: " + (a + b) + "\n");
			}

			else if(ch == 2)
			{
				System.out.println("Difference: " + (a - b) + "\n");
			}

			else if(ch == 3)
			{
				System.out.println("Product: " + (a * b) + "\n");
			}

			else if(ch == 4)
			{
				System.out.println("Quotient: " + (a / b) + "\n");
			}

			else
			{
				cont = false;
			}
		}
	}
}
