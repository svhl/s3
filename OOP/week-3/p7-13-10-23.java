// create a class hierarchy for animals, including a base class "Animal," a subclass "Herbivore", & another subclass "Carnivore"
// "Animal" class should have attributes like name, age & subclass should have the attribute type of "Animal"
//  use the super keyword to call the constructor of the superclass when creating objects of subclasses
//  demonstrate hierarchical inheritance and attribute initialization with the super keyword
//  include a method in subclasses to display the details of the animals

import java.util.Scanner;
class Animal
{
	String name;
	int age;

	Animal(String n, int a)
	{
		name = n;
		age = a;
	}

	void display()
	{
		System.out.println("\nName: " + name);
		System.out.println("Age: " + age);
	}
}

class Herbivore extends Animal
{
	String type;

	Herbivore(String n, int a, String t)
	{
		super(n, a);
		type = t;
	}

	void display()
	{
		super.display();
		System.out.println("Type: " + type);
	}
}

class Carnivore extends Animal
{
	String type;

	Carnivore(String n, int a, String t)
	{
		super(n, a);
		type = t;
	}

	void display()
	{
		super.display();
		System.out.println("Type: " + type);
	}
}

class AnimalDemo
{
	public static void main(String[] args)
	{
		String name, type;
		int age;
		Scanner sc = new Scanner(System.in);

		System.out.println("Case 1: Herbivore");
		System.out.println("Enter name:");
		name = sc.nextLine();
		System.out.println("Enter age:");
		age = sc.nextInt();
		System.out.println("Enter type:");
		sc.nextLine();
		type = sc.nextLine();

		Herbivore h1 = new Herbivore(name, age, type);
		h1.display();

		System.out.println("\nCase 2: Carnivore");
		System.out.println("Enter name:");
		name = sc.nextLine();
		System.out.println("Enter age:");
		age = sc.nextInt();
		System.out.println("Enter type:");
		sc.nextLine();
		type = sc.nextLine();

		Carnivore c1 = new Carnivore(name, age, type);
		c1.display();
	}
}
