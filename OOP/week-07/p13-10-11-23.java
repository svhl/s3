// write a java program to implement an ATM for State Bank of India
// customers of the bank can withdraw, deposit money, transfer money, and view available balance
// account balance of all customers are stored in a file having file name same as their account number
// throw an exception during withdrawal if sufficient balance isn't available
// use finally block to ensure that available balance is displayed & that the file is closed after every transaction
// handle all possible exceptions related to file

import java.util.*;
import java.io.*;

class atm
{
	public static void main(String[] args)
	{
		String ano1 = "", ano2;
		int ch;
		double bal1 = 0, bal2, amt;
		Scanner sc = new Scanner(System.in);
		
		try
		{
			System.out.println("State Bank of India");
			System.out.println("Enter account no.:");
			ano1 = sc.next();

			try
			{
				FileReader f1r = new FileReader(ano1);
				Scanner s1 = new Scanner(f1r);
				bal1 = s1.nextDouble();
				f1r.close();
			}
			
			catch(IOException e)
			{
				System.out.println("\nAccount doesn't exist\n" + e);
				FileWriter f1w = new FileWriter(ano1);
				System.out.println("Creating new account with zero balance");
				bal1 = 0;
				f1w.write(Double.toString(bal1));
				f1w.close();
				return;
			}
		}
		
		catch(Exception e)
		{
			System.out.println(e);
		}
		
		while(true)
		{
			try
			{				
				System.out.println("\n1. Withdraw");
				System.out.println("2. Deposit");
				System.out.println("3. Transfer");
				System.out.println("4. Display balance");
				System.out.println("Any other value to exit");
				System.out.println("Enter choice:");
				ch = sc.nextInt();
				
				if(ch == 1)
				{
					System.out.println("\nEnter amount to withdraw:");
					amt = sc.nextDouble();
					
					if(amt > bal1)
					{
						throw new ArithmeticException("\nInsufficient balance");
					}
					
					bal1 = bal1 - amt;
				}
				
				else if(ch == 2)
				{
					System.out.println("\nEnter amount to deposit:");
					amt = sc.nextDouble();
					bal1 = bal1 + amt;
				}
				
				else if(ch == 3)
				{
					System.out.println("\nEnter recipient's account no.:");
					ano2 = sc.next();
					FileReader f2r = new FileReader(ano2);
					Scanner s2 = new Scanner(f2r);
					bal2 = s2.nextDouble();
					f2r.close();
					System.out.println("Enter amount to transfer:");
					amt = sc.nextDouble();
					
					if(amt > bal1)
					{
						throw new ArithmeticException("\nInsufficient balance");
					}

					bal1 = bal1 - amt;
					amt = amt + bal2;
					FileWriter f2w = new FileWriter(ano2);
					f2w.write(Double.toString(amt));
					f2w.close();
				}

				else if(ch == 4)
				{
				}
				
				else
				{
					return;
				}
			}

			catch(ArithmeticException e)
			{
				System.out.println("\n" + e);
			}
			
			catch(FileNotFoundException e)
			{
				System.out.println("\nAccount doesn't exist\n" + e);
			}

			catch(Exception e)
			{
				System.out.println("\n" + e);
			}
			
			finally
			{
				try
				{
					FileWriter f1w = new FileWriter(ano1);
					System.out.println("\nBalance: " + bal1);
					f1w.write(Double.toString(bal1));
					f1w.close();
				}

				catch(Exception e)
				{
					System.out.println("\n" + e);
				}
			}
		}
	}
}
