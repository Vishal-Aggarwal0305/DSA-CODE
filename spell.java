//import java.util.HashSet;
//import java.util.Scanner;
//import java.util.Set;
//
//public class spell {
//    Scanner sc = new Scanner(System.in);
//    int T = sc.nextInt();
//    while(T-->0)
//    {
//        Scanner sc = new Scanner(System.in);
//        int n = sc.nextInt();
//        int[] ar = new int[n];
//        for(int i=0;i<n;i++)
//        {
//            ar[i] = sc.nextInt();
//        }
//
//        int oddcount=0 ,evenCount=0;
//        for(int i=0;i<n;i++)
//        {
//            if(ar[i] > 0 )
//            {
//                evenCount++;
//            }
//            if(ar[i]<0)
//            {
//                oddcount++;
//            }
//        }
//
//        if(evenCount%2==0 && oddcount%2!=0)
//        {
//            return "POSSIBLe";
//        }
//        return"IMPOSSIBLE");


//        String s = sc.next();
//        Set<Character> hs = new HashSet<>();
//        hs.add('T');
//        hs.add('i');
//        hs.add('m');
//        hs.add('u');
//        hs.add('r');
//
//        for(char ch : s.toCharArray())
//        {
//            if(hs.contains(ch))
//            {
//                hs.remove(ch);
//            }
//            else
//            {
//                break;
//            }
//        }
//
//        if(hs.isEmpty())
//        {
//            System.out.println("YES");
//        }
//        else
//        {
//            System.out.println("NO");
//        }
//
//
//    }
//}
//
//int res = 0;
//int n = mat.length;
//for (int i=0; i<n; i++) {
//    res += mat[i][i];
//    res += mat[n-1-i][i];
//}
//return n % 2 == 0 ? res : res - mat[n/2][n/2];