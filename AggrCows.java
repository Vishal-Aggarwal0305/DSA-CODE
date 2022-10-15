package Arrays;

import java.util.*;

public class AggrCows {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while (t-- > 0) {
			int nos = sc.nextInt();
			int noc = sc.nextInt();
			int[] stalls = new int[nos];
			for (int i = 0; i < stalls.length; i++) {
				stalls[i] = sc.nextInt();
			}

			Arrays.sort(stalls);

			System.out.println(LargestMinDistance(stalls, noc));
		}

	}

	public static int LargestMinDistance(int[] stalls, int noc) {

		int lo = 0;
		int hi = stalls[stalls.length - 1];
		int ans = 0;

		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (isitPossible(stalls, mid, noc) == true) {
				ans = mid;
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}

		return ans;
	}

	private static boolean isitPossible(int[] stalls, int mid, int noc) {
		int cows = 1;
		int pos = stalls[0];
		int i = 1;
		while (i < stalls.length) {
			if (stalls[i] - pos >= mid) {
				cows++;
				pos = stalls[i];
			}

			if (cows == noc) {
				return true;
			}
			i++;
		}
		return false;
	}

}
