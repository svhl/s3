// implement a simple file encryption program that reads a text file, encrypts its contents & saves the encrypted data to a new file
// use a simple substitution cipher such as shifting characters by a fixed number

import java.util.*;
import java.io.*;

class Encrypt
{
	public static void main(String[] args) throws IOException
	{
		int i;
		String iname, oname;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter input filename:");
		iname = sc.next();
		System.out.println("Enter output filename:");
		oname = sc.next();
		FileInputStream fin = new FileInputStream(iname);
		FileOutputStream fout = new FileOutputStream(oname);

		while((i = fin.read()) != -1)
		{
			fout.write((char)(i - 2));
		}

		System.out.println("Done");
		fin.close();
		fout.close();
	}
}
