int minCost(char * colors, int* neededTime, int neededTimeSize){
    int i,min=0,sum=0;
    for(i=1;i<=neededTimeSize;i++){
        if(colors[i]==colors[i-1]){
           // min=neededTime[i-1];
            if(neededTime[i-1]>neededTime[i] ){
                min=neededTime[i];
                neededTime[i]=neededTime[i-1];
            }
            else{
                min=neededTime[i-1];
            }
            //c++;
            sum=sum+min;
        }
        
        
    }
    //if(colors)
    return sum;
}
