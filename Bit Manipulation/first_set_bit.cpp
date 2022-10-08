
class Solution
{
    public:
    //Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
        // Your code here
        int count=0;
        while(n)
        {
            count++;
            if(n&1)
            return count;
            
            n=n>>1;
        }
        return count;
    }
};