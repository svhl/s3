// design a class hierarchy for employees, including a base class "Employee" & multiple levels of subclasses such as "Manager", "Developer" & "Intern"
// each subclass should inherit attributes from the base class & add specific attributes & methods
// create instances of these subclasses to represent different roles within a company
// introduce another level of subclasses eg. "SeniorManager", "JuniorDeveloper"
// each subclass should override methods inherited from its parent class to provide specialized behavior

import java.util.Scanner;

class Employee
{
	String name, role;
	int id;

	Employee(String name, String role, int id)
	{
		this.name = name;
		this.role = role;
		this.id = id;
	}

	void display()
	{
		System.out.println("\nName: " + name);
		System.out.println("Role: " + role);
		System.out.println("ID: " + id);
	}
}

class Manager extends Employee
{
	String dept;

	Manager(String name, String role, int id, String dept)
	{
		super(name, role, id);
		this.dept = dept;
	}

	void display()
	{
		super.display();
		System.out.println("Department: " + dept);
	}
}

class SeniorManager extends Manager
{
	int tsize;

	SeniorManager(String name, String role, int id, String dept, int tsize)
	{
		super(name, role, id, dept);
		this.tsize = tsize;
	}

	void display()
	{
		super.display();
		System.out.println("Team size: " + tsize);
	}
}

class Developer extends Employee
{
	String language;

	Developer(String name, String role, int id, String language)
	{
		super(name, role, id);
		this.language = language;
	}

	void display()
	{
		super.display();
		System.out.println("Language: " + language);
	}
}

class JuniorDeveloper extends Developer
{
	String mentor;

	JuniorDeveloper(String name, String role, int id, String language, String mentor)
	{
		super(name, role, id, language);
		this.mentor = mentor;
	}

	void display()
	{
		super.display();
		System.out.println("Mentor: " + mentor);
	}
}

class Intern extends Employee
{
	String cname;

	Intern(String name, String role, int id, String cname)
	{
		super(name, role, id);
		this.cname = cname;
	}

	void display()
	{
		super.display();
		System.out.println("College: " + cname);
	}
}

class EmployeeDemo
{
	public static void main(String[] args)
	{
		String name, role, dept, language, mentor, cname;
		int id, tsize;
		Scanner sc = new Scanner(System.in);
		System.out.println("Menu");
		System.out.println("1. Senior manager");
		System.out.println("2. Junior developer");
		System.out.println("3. Intern");
		System.out.println("Any other value to exit");
		System.out.println("Enter choice");
		int ch = sc.nextInt();
		
		if(ch < 1 || ch > 3)
		{
			return;
		}
		
		sc.nextLine();
		System.out.println("\nEnter name:");
		name = sc.nextLine();
		System.out.println("Enter role:");
		role = sc.nextLine();
		System.out.println("Enter ID:");
		id = sc.nextInt();
		
		if(ch == 1)
		{
			System.out.println("Enter team size:");
			tsize = sc.nextInt();
			System.out.println("Enter department:");
			sc.nextLine();
			dept = sc.nextLine();

			SeniorManager sm1 = new SeniorManager(name, role, id, dept, tsize);
			sm1.display();
		}
		
		else if(ch == 2)
		{
			sc.nextLine();
			System.out.println("Enter language:");
			language = sc.nextLine();
			System.out.println("Enter mentor:");
			mentor = sc.nextLine();

			JuniorDeveloper jd1 = new JuniorDeveloper(name, role, id, language, mentor);
			jd1.display();
		}
		
		else if(ch == 3)
		{
			sc.nextLine();
			System.out.println("Enter college:");
			cname = sc.nextLine();

			Intern i1 = new Intern(name, role, id, cname);
			i1.display();
		}
	}
}
