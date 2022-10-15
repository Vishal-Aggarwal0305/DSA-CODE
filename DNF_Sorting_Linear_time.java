package Arrays;

import java.util.Scanner;

public class DNF_Sorting_Linear_time {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] arr = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = sc.nextInt();
		}
		DNF_sort(arr);
		display(arr);

	}
	public static void DNF_sort(int[] arr) {
		int left = 0;
		int right = arr.length-1;
		int mid = 0;
		while(mid <= right) {
			if(arr[mid] == 2) {
				int t = arr[right];
				arr[right] = arr[mid];
				arr[mid] = t;
				right--;
			}
			else if (arr[mid] == 0) {
				int t = arr[left];
				arr[left] = arr[mid];
				arr[mid] = t;
				left++;
				mid++;
			}
			else {
				mid++;
			}
		}
	}
	public static void display(int[] arr) {
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
	}

}
