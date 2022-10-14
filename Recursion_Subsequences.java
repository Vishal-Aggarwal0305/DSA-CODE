package Recursion;

import java.util.*;

public class Recursion_Subsequences {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String str = sc.next();
		ArrayList<String> arr = new ArrayList<>();
		String ans = "";
		arr = PrintSubseq(str, ans, arr);
		for (String string : arr) {
			System.out.print(string + " ");
		}
		System.out.println();
		System.out.println(arr.size());
	}

	public static ArrayList<String> PrintSubseq(String str, String ans, ArrayList<String> arr) {
		if(str.length() == 0) {
			
			arr.add(ans);
			return arr;
		}
		
		char ch = str.charAt(0);

		PrintSubseq(str.substring(1), ans, arr);
		return PrintSubseq(str.substring(1), ans+ch, arr);
		
	}

}
