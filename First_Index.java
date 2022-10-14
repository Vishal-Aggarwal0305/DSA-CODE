package Recursion;

import java.util.*;

public class First_Index {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] arr = new int[n];
		for (int i = 0; i < arr.length; i++) {
			arr[i] = sc.nextInt();
		}
		int m = sc.nextInt();
		int i = 0;
		System.out.println(FI(arr, i, m));

	}

	public static int FI(int[] arr, int i, int m) {
		if (i >= arr.length) {
			return -1;
		}
		if (arr[i] == m) {
			return i;
		}

		return FI(arr, i + 1, m);

	}
}
