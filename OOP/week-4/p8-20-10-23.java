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
	int teamsize;

	Manager(String name, String role, int id, int teamsize)
	{
		super(name, role, id);
		this.teamsize = teamsize;
	}

	void display()
	{
		super.display();
		System.out.println("Team size: " + teamsize);
	}
}

class SeniorManager extends Manager
{
	String dept;

	SeniorManager(String name, String role, int id, int teamsize, String dept)
	{
		super(name, role, id, teamsize);
		this.dept = dept;
	}

	void display()
	{
		super.display();
		System.out.println("Department: " + dept);
	}
}

class JuniorManager extends Manager
{
	String mentor;

	JuniorManager(String name, String role, int id, int teamsize, String mentor)
	{
		super(name, role, id, teamsize);
		this.mentor = mentor;
	}

	void display()
	{
		super.display();
		System.out.println("Mentor: " + mentor);
	}
}

class EmployeeDemo
{
	public static void main(String[] args)
	{
		String name, role, dept, mentor;
		int id, teamsize;
		Scanner sc = new Scanner(System.in);

		System.out.println("Case 1: Senior Manager\n");
		System.out.println("Enter name:");
		name = sc.nextLine();
		System.out.println("Enter role:");
		role = sc.nextLine();
		System.out.println("Enter ID:");
		id = sc.nextInt();
		System.out.println("Enter team size:");
		teamsize = sc.nextInt();
		System.out.println("Enter department:");
		sc.nextLine();
		dept = sc.nextLine();

		SeniorManager sm1 = new SeniorManager(name, role, id, teamsize, dept);
		sm1.display();

		System.out.println("\nCase 2: Junior Manager\n");
		System.out.println("Enter name:");
		name = sc.nextLine();
		System.out.println("Enter role:");
		role = sc.nextLine();
		System.out.println("Enter ID:");
		id = sc.nextInt();
		System.out.println("Enter team size:");
		teamsize = sc.nextInt();
		System.out.println("Enter mentor:");
		sc.nextLine();
		mentor = sc.nextLine();

		JuniorManager jm1 = new JuniorManager(name, role, id, teamsize, mentor);
		jm1.display();
	}
}
