  public:
    long long reversedBits(long long X) {
        
            long long result = 0;
       
       for(int i=0;i < 32;i++){
           result = result << 1;
           
           if((X&1) == 1){
                result++;
           }
           
           X = X >> 1;
            
       }
       
       return result;
       
        
    }
};