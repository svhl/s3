// create a java class for bank account
// include attributes like account no., account holder's name, balance
// implement methods to display money, withdraw money, check balance, display account details
// create 2 objects & initialize their parameters using different types of constructors

import java.util.Scanner;
class Bank
{
	int anum;
	String name;
	double bal;
	
	Bank()
	{
		anum = 123456789;
		name = "Name";
		bal = 10;
	}
	
	Bank(int a, String n, double b)
	{
		anum = a;
		name = n;
		bal = b;
	}
	
	void Deposit(double amt)
	{
		bal += amt;
		System.out.println("Deposited " + amt);
	}
	
	void Withdraw(double amt)
	{
		if(amt > bal)
		{
			System.out.println("Can't withdraw because insufficient balance");
		}

		else
		{
			bal -= amt;
			System.out.println("Withdrew " + amt);
		}
	}
	
	void Balance()
	{
		System.out.println("New balance is " + bal);
	}
	
	void Display()
	{
		System.out.println("Account no.: " + anum);
		System.out.println("Name: " + name);
		System.out.println("Balance: " + bal + "");
	}
}

class BankDemo
{
	public static void main(String[] args)
	{
		int anum;
		String name;
		double bal, amt;
		
		System.out.println("Default constructor\n");

		Bank b1 = new Bank();
		b1.Deposit(10000);
		b1.Withdraw(6500);
		b1.Balance();
		System.out.println();
		b1.Display();

		System.out.println("\nParameterized constructor\n");

		Scanner sc = new Scanner(System.in);
		System.out.println("Enter account no.:");
		anum = sc.nextInt();
		System.out.println("Enter name:");
		sc.nextLine();
		name = sc.nextLine();
		System.out.println("Enter balance:");
		bal = sc.nextDouble();

		Bank b2 = new Bank(anum, name, bal);
		System.out.println("\nEnter amount to deposit:");
		amt = sc.nextDouble();
		b2.Deposit(amt);
		System.out.println("\nEnter amount to withdraw:");
		amt = sc.nextDouble();
		b2.Withdraw(amt);
		b2.Balance();
		System.out.println();
		b2.Display();
	}
}
