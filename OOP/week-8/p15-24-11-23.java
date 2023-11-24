class Display
{
	synchronized void display(int n)
	{
		try
		{
			for(int i = n; i <= 10; i += 2)
			{
				System.out.println(i);
				Thread.sleep(1500);
				System.out.println(i);
			}
		}
		
		catch(InterruptedException e)
		{
			System.out.println("Thread interrupted");
		}
	}
}

class even implements Runnable
{
	Display d = new Display();
	
	even(Display display)
	{
		d = display;
		Thread even = new Thread(this);
		even.start();
	}
	
	public void run()
	{
		d.display(0);
	}
}

class odd implements Runnable
{
	Display d = new Display();
	
	odd(Display display)
	{
		d = display;
		Thread odd = new Thread(this);
		odd.start();
	}
	
	public void run()
	{
		d.display(1);
	}
}

class ThreadDemo
{
	public static void main(String[] args)
	{
		Display d = new Display();
		even e = new even(d);
		odd o = new odd(d);
	}
}
