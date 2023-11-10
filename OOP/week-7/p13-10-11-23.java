import java.util.*;
import java.io.*;

class atm
{
	public static void main(String[] args)
	{
		try
		{
			String acc, racc;
			int ch;
			double bal, rbal, amt;
			Scanner sc = new Scanner(System.in);
			System.out.println("State Bank of India");
			System.out.println("Enter account no.:");
			acc = sc.next();

			try
			{
				FileReader faccread = new FileReader(acc);
				Scanner sf = new Scanner(faccread);
				bal = sf.nextDouble();
				faccread.close();
			}
			
			catch(FileNotFoundException e)
			{
				System.out.println("Account doesn't exist\n" + e);
				FileWriter faccwrite = new FileWriter(acc);
				System.out.println("File doesn't exist, balance set as 0");
				bal = 0;
				faccwrite.write(Double.toString(bal));
				faccwrite.close();
				return;
			}
			
			System.out.println("1. Withdraw");
			System.out.println("2. Deposit");
			System.out.println("3. Transfer");
			System.out.println("Any other value to exit");
			System.out.println("Enter choice:");
			ch = sc.nextInt();
			
			if(ch == 1)
			{
				try
				{
					System.out.println("Enter amount to withdraw:");
					amt = sc.nextDouble();
					
					if(amt > bal)
					{
						throw new ArithmeticException("Insufficient balance");
					}
					
					bal = bal - amt;
				}
				
				catch(ArithmeticException e)
				{
					System.out.println(e);
				}
			}
			
			else if(ch == 2)
			{
				System.out.println("Enter amount to deposit:");
				amt = sc.nextDouble();
				bal = bal + amt;
			}
			
			else if(ch == 3)
			{
				System.out.println("Enter recipient's account no.:");
				racc = sc.next();
				
				try
				{
					FileReader fraccread = new FileReader(racc);
					Scanner sr = new Scanner(fraccread);
					rbal = sr.nextDouble();
					sr.close();
					fraccread.close();
				}
				
				catch(FileNotFoundException e)
				{
					System.out.println("Account doesn't exist\n" + e);
					return;
				}
				
				System.out.println("Enter amount to transfer:");
				amt = sc.nextDouble();
				double res = amt + bal;
				FileWriter fraccwrite = new FileWriter(racc);
				fraccwrite.write(Double.toString(res));
				fraccwrite.close();
			}
			
			else
			{
				System.out.println("Wrong choise");
			}
		}
		
		catch(Exception e)
		{
			System.out.println(e);
		}
		
		finally
		{
		}
	}
}
