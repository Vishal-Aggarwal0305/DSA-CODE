package Arrays;

import java.util.*;

public class Book_Allocation_Problem {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while (t-- > 0) {
			int nop = sc.nextInt();
			int nos = sc.nextInt();
			int[] pages = new int[nop];
			for (int i = 0; i < pages.length; i++) {
				pages[i] = sc.nextInt();
			}

			System.out.println(minPages(pages, nos));

		}

	}

	public static int minPages(int[] pages, int nos) {
		int lo = 0;
		int hi = 0;
		for (int i = 0; i < pages.length; i++) {
			hi += pages[i];
		}

		int ans = 0;
		while (lo <= hi) {

			int mid = (lo + hi) / 2;

			if (isitPossible(pages, mid, nos) == true) {
				ans = mid;
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}

		return ans;
	}

	public static boolean isitPossible(int[] pages, int mid, int nos) {

		int students = 1;
		int pages_read = 0;
		int i = 0;
		while (i < pages.length) {
			if (pages_read + pages[i] <= mid) {
				pages_read += pages[i];
				i++;
			} else {
				students = students + 1;
				pages_read = 0;
			}

			if (students > nos) {
				return false;
			}
		}

		return true;
	}
}
