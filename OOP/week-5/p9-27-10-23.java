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
		FileWriter fwr = new FileWriter(iname); 
		System.out.println("Enter number of numbers:");
		n = sc.nextInt();
		
		for(int i = 0; i < n; i++)
		{
			System.out.println("Enter number " + (i+1) + ":");
			int num = sc.nextInt();
			fwr.write(num + "\t");
		}
		
		fwr.close(); 
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
			
			if(count==0)
			{
				fop.write(Integer.toString(num)+"\t");
			}
		}

		fin.close();
		fop.close();
	}
}
