import java.util.*;
import java.io.*;

public class SortTheArray {

  public static void main(String[] args)throws IOException {
        Scanner sc=new Scanner(System.in);
     int n=sc.nextInt();
     int[] a=new int[n];
     int i;
     for (i=0;i<n;i++){
         a[i]=sc.nextInt();
     }
     int s=0,e=0;
     boolean b=false;
     int c=0;
     for(i=1;i<n;i++) {
         if (a[i] < a[i - 1] && !b) {
             s = i-1 ;
             b = true;
             c++;
         }
         else if (a[i] > a[i - 1] && b) {
                 e = i-1 ;
                 b = false;

         }
         if (c > 1) break;
     }
     if(b) e=n-1;
     if(i!=n) System.out.println("no");
     else {
         if(s==0 && e==n-1) {
             System.out.println("yes");
             System.out.println((s + 1) + " " + (1 + e));
         }
         else if(s==0 ) {
             if (a[s] < a[e+1]){
             System.out.println("yes");
             System.out.println((s + 1) + " " + (1 + e));}
             else System.out.println("no");
         }
        else if(e==n-1 ) {
            if (a[e] > a[s-1]) {
                System.out.println("yes");
                System.out.println((s + 1) + " " + (1 + e));
            }
            else{
                System.out.println("no");
            }
         }
         else if(a[s] < a[e+1] && a[e] > a[s-1]) {
             System.out.println("yes");
             System.out.println((s + 1) + " " + (1 + e));
         }
        else
             System.out.println("no");
     }
    }
}
