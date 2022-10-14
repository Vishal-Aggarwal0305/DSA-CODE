public class LIS_NLogN {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int[] arr = {0,8,4,12,2,10,6,14,1,9,5,13,11,7,15};
		System.out.println(lis(arr));

	}
	
	
	public static int lis(int[] arr)
	{
		int[] lis = new int[arr.length];
		lis[0] = arr[0];
		int len = 0;
		
		for(int i = 1; i < arr.length; i++)
		{
			if(arr[i] > lis[len])
			{
				len++;
				lis[len] = arr[i];
			}
			else
			{
				int id = bs(lis,arr[i],0,len);
				lis[id] = arr[i];
			}
		}
//		System.out.println(Arrays.toString(lis));
		return len+1;
		
	}
	
	public static int bs(int[] arr, int ele, int si, int ei)
	{
		int ans = 0;
		while(si <= ei)
		{
			int mid = (si+ei)/2;
			if(arr[mid] >= ele)
			{
				ans = mid;
				ei = mid-1;
			}
			else
			{
				si = mid+1;
			}
		}
		
		return ans;
	}

}
