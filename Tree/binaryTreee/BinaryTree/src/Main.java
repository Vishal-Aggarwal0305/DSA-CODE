import java.util.*;

public class Main {

    public static void main(String[] args) {
//        Scanner sc = new Scanner(System.in);
//        int n = sc.nextInt();
//        int[] ar = new int[n];
//
//        for(int i=0;i<n;i++)
//        {
//            ar[i] = sc.nextInt();
//        }
//        Arrays.sort(ar);
//        System.out.println(ar[n/2]);

   int[] ar = {10,9,2,5,3,7,101,18};
   int localMax=0,globalMAx=0;
   for(int i=0;i<ar.length;i++)
   {
       localMax=Math.max(localMax,ar[i]+localMax);
       if(localMax> globalMAx)
       {
           globalMAx=localMax;
       }
   }

   System.out.println(globalMAx);


//        BinaryTreeSearch b = new BinaryTreeSearch();
//        b.inset(21);
//        b.inset(41);
//        b.inset(30);
//        b.inset(16);
//        b.inset(76);
//        b.inset(65);
//        b.inset(50);
//        b.inset(26);
//        b.inset(29);

//        String s1 = "ABCBDAB";
//        String s2 = "BDCABA";
//
//        int[][] dp = new int[s1.length()+1][s2.length()+1];
//
//        for(int i=1;i<=s1.length();i++)
//        {
//            for(int j=1;j<=s2.length();j++)
//            {
//                if(s1.charAt(i-1) == s2.charAt(j-1))
//                {
//                    dp[i][j] = 1 + dp[i-1][j-1];
//                }
//                else {
//                    dp[i][j] = Math.max(dp[i-1][j],dp[i][j-1]);
//                }
//            }
//        }
//
//        int idx = dp[s1.length()][s2.length()];
//        char[] res = new char[idx+1];
//
//        int i=s1.length(),j=s2.length(),k=idx-1;
//        while(i>0 && j>0)
//        {
//            if(s1.charAt(i-1) == s2.charAt(j-1))
//            {
//                res[k--]=s1.charAt(i-1);
//                i--;
//                j--;
//            }
//            else if(dp[i-1][j] > dp[i][j-1] )
//            {
//                i--;
//            }
//            else {
//                j--;
//            }
//        }
//
////        System.out.println(String.valueOf(res));
//        String string = "ELRMENMET";
//        StringBuilder sb = new StringBuilder();
//        sb.append(string);
//        sb.reverse();
//        Integer [][]dp = new Integer[string.length()][string.length()];

//        int[] dp  = new int[298];
//        System.out.println(minvalue(297,dp));

//        System.out.println(LPSLength(dp,string,sb.toString(),0,0));

    }
//        public static int LPSLength(Integer [][]dp,String str,String reverseStr,int m,int n)
//        {
//            if(m>=str.length() || n>=reverseStr.length())
//            {
//                return 0;
//            }
//
//            int c1=0;
//            if(dp[m][n] == null)
//            {
//
//                if(str.charAt(m) == reverseStr.charAt(n))
//                {
//                    c1 = 1+ LPSLength(dp,str,reverseStr,m+1,n+1);
//                }
//
//                int c2 = LPSLength(dp,str,reverseStr,m+1,n);
//                int c3 = LPSLength(dp,str,reverseStr,m,n+1);
//
//                dp[m][n] = Math.max(c1,Math.max(c2,c3));
//            }
//
//            return dp[m][n];
//        }

    public static int minvalue(int num,int[] dp)
    {
        if(num<=9)
        {
            return 0;
        }

        ArrayList<Integer> hs = new ArrayList<>();

        while(num>0)
        {
            hs.add(num%10);
            num/=10;
        }
        if(dp[num]==0) {
            int min = Integer.MAX_VALUE;
            while (!hs.isEmpty()) {
                int temp = 1 + minvalue(num - hs.remove(0), dp);
                min=Math.min(min,temp);
            }
            dp[num]=min;
            return dp[num];
        }

        return dp[num];
    }

}