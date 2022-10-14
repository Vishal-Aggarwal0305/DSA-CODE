public class ith_bit {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(check_ith(7, 3));

	}
	
	public static boolean check_ith(int n,int i)
	{
		int mask = 1<<i-1;
		if((n&mask) != 0)
		{
			return true;
		}
		else
			return false;
	}

}
