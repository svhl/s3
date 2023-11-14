// write a java program to demonstrate the use of garbage collectors

class GarbageCollection
{
	public void finalize()
	{
		System.out.println ("Garbage Collection performed by JVM");
	}

	public static void main (String args[])
	{
		GarbageCollection s1 = new GarbageCollection();
		GarbageCollection s2 = new GarbageCollection();
		s1 = null;
		s2 = null;
		System.gc();
		System.runFinalization();
	}
}
