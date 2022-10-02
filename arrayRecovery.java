import java.util.*;

public class arrayRecovery {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while(T-->0)
        {
            int n = sc.nextInt();

            int[] a = new int[n];
            int[] d = new int[n];

            for(int i=0;i<n;i++)
            {
                d[i] = sc.nextInt();
            }

            boolean isRecover = true;
            a[0] = d[0];
            for(int i=1;i<n;i++)
            {
                if( d[i]==0)
                {
                    a[i] = a[i-1];
                }
                else {
                    if( d[i]<a[i-1])
                    {
                        isRecover = false;
                        break;
                    }
                    a[i]=a[i-1] + d[i];
                }
            }

            if(!isRecover)
            {
                System.out.println(-1);
            }
            else {
                for(int i=0;i<n;i++)
                {
                    System.out.print(a[i]+" ");
                }
            }

        }

    }
}