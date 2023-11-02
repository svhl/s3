// write a program to read numbers in a file & copy the prime numbers among them into another file

import java.util.*;
import java.io.*;

class Prime
{
	public static void main(String[] args) throws IOException
	{
		int n;
		String iname, oname;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter input filename:");
		iname = sc.next();
		System.out.println("Enter output filename:");
		oname = sc.next();
		FileReader fin = new FileReader(iname);
		FileWriter fop = new FileWriter(oname);
		Scanner fs = new Scanner(fin);
		
		while(fs.hasNextInt() == true)
		{
			int count = 0;
			int num = fs.nextInt();
			
			for(int i = 2; i <= num / 2; i++)
			{
				if(num % i == 0)
				{
					count++;
				}
			}
			
			if(count==0 && num != 0 && num != 1)
			{
				fop.write(Integer.toString(num)+"\t");
			}
		}

		System.out.println("Done");
		fin.close();
		fop.close();
	}
}
