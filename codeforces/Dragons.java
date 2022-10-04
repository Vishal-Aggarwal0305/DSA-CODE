package codeforce;

import java.util.*;
import java.io.*;

public class Dragons {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int s=sc.nextInt(),n=sc.nextInt();
        int[] x=new int[n];
        int[] y=new int[n];
        int i;
        for(i=0;i<n;i++)
        {
            x[i]=sc.nextInt();
            y[i]=sc.nextInt();
        }
        selectionS(x,y,n);
        for(i=0;i<n;i++)
        {
            if(s>x[i])
            {
                s=s+y[i];
            }
            else
                break;
        }
        if(i==n)
            System.out.println("YES");
        else
            System.out.println("NO");
    }
    static void selectionS(int[] x,int[] y,int n)
    {
        int i,j,sm;
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(x[j]<x[i]){
                   sm=x[j];
                   x[j]=x[i];
                   x[i]=sm;

                   sm=y[j];
                   y[j]=y[i];
                   y[i]=sm;
                }
            }
        }
    }
}
