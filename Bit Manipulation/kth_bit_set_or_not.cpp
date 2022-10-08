

class Solution
{
    public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k)
    {
        int p=1<<k;
        if(p&n)
        return 1;
        return 0;
    }
};