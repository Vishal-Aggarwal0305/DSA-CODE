public class PrintSubSequences {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		allSS("abc");

	}
	
	public static void allSS(String s)
	{
		int x = s.length();
		for(int i = 0; i < (1<<x); i++)
		{
			printSS(s, i);
		}
	}
	public static void printSS(String s, int n)
	{
		int i = 0;
		while(n != 0)
		{
			if((n&1) == 1)
			{
				System.out.print(s.charAt(i));
			}
			i++;
			n = n >> 1;
		}
		System.out.println();
	}

}
