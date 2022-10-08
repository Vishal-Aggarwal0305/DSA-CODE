class Solution {
public:
    long long int  total_count(long long int n) 
    {
        // Code here.
       long long count=0;
        while(n)
        {
           if(!(n&1))count++;
           n=n>>1;
        }
       return 1*1LL<<count;
    }
};