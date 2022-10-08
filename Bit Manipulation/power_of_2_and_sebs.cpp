public:
    long long numberOfSubsequences(int N, long long A[]){
        // code here
        int ans=1;
        int o=1e9+7;
        for(int i=0;i<N;i++)
        {
            if((A[i]&(A[i]-1))==0)
             ans=(ans*2)%o;
        }
        return ans-1;
    }
};