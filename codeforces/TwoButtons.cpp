package codeforce;

import java.util.*;

public class TwoButtonsPrac {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        {
            int n=sc.nextInt();
            int m=sc.nextInt();
            int count=0;
            while(n!=m)
            {
                m= ((m&1)==1 || m<n) ? ++m : m/2;
                count++;
            }
            System.out.println(count);
        }
    }
}
