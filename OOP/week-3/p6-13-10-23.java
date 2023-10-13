import java.util.Scanner;
class Bank
{
	int anum;
	String name;
	double bal;
	
	Bank()
	{
		System.out.println("\nDefault constructor\n");
		anum = 123456789;
		name = "Name";
		bal = 10;
	}
	
	Bank(int a, String n, double b)
	{
		System.out.println("\nParameterized constructor\n");
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
		bal -= amt;
		System.out.println("Withdrew " + amt);
	}
	
	void Balance()
	{
		System.out.println("New balance is " + bal);
	}
	
	void Display()
	{
		System.out.println("Account no.: " + anum);
		System.out.println("Name: " + name);
		System.out.println("Balance: " + bal + "\n");
	}
}

class BankDemo
{
	public static void main(String[] args)
	{
		int anum;
		String name;
		double bal, amt;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter account no.:");
		anum = sc.nextInt();
		System.out.println("Enter name:");
		sc.nextLine();
		name = sc.nextLine();
		System.out.println("Enter balance:");
		bal = sc.nextDouble();
		
		Bank b1 = new Bank(anum, name, bal);
		b1.Display();
		System.out.println("Enter amount to deposit:");
		amt = sc.nextDouble();
		b1.Deposit(amt);
		System.out.println("Enter amount to withdraw:");
		amt = sc.nextDouble();
		b1.Withdraw(amt);
		b1.Balance();
		
		Bank b2 = new Bank();
		b2.Display();
		b2.Deposit(10000);
		b2.Withdraw(6500);
		b2.Balance();
	}
}
