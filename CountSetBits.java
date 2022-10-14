public class CountSetBits {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
//		System.out.println(countSBO(-1));
		firstSetBit(168);

	}
	
	public static int countSB(int n)
	{
		int count = 0;
		while(n!=0)
		{
			if((n&1) != 0)
				count++;
			n = n >> 1;
		}
		return count;
	}
	
	public static int countSBO(int n)
	{
		int count = 0;
		while(n != 0)
		{
			count++;
			n = n &(n-1);
		}
		return count;
	}
	
	public static void firstSetBit(int n)
	{
//		int a = 1;
//		while(true)
//		{
//			if((n&1) != 0)
//			{
//				break;
//			}
//			else
//			{
//				n = n>>1;
//				a = a<<1;
//			}
//		}
//		System.out.println(a);
		
		int a = n & (~(n-1));
		
		System.out.println(a);
	}

}
