package Arrays;

import java.util.Scanner;

public class trapping_rain_water {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
//		int n = sc.nextInt();
		int[] arr = {0,1,0,2,1,0,1,3,2,1,2,1};
//		int[] arr = new int[n];
//		for (int i = 0; i < n; i++) {
//			arr[i] = sc.nextInt();
//		}
		System.out.println(trap(arr));
	}

	public static int trap(int[] arr) {
		int n = arr.length;
		int[] left = new int[n];
		int[] right = new int[n];
		left[0] = arr[0];
		for (int i = 1; i < n; i++) {
			left[i] = Math.max(left[i - 1], arr[i]);
		}

		right[n - 1] = arr[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			right[i] = Math.max(right[i + 1], arr[i]);
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			int min = Math.min(left[i], right[i]);
			ans +=  min - arr[i];
		}

		return ans;

	}

}
