#include<iostream>
using namespace std;

int main(){

//Using const int for array size
    const int row=2,col=2;
// if not use const error found

cout<<"Size of Matrices : "<<row<<" X "<<col<<endl;
cout<<"Enter Value For First Matrix:"<<endl;

int first[row][col], second[row][col];

int x,j;
for( x=0;x<row;x++){

    cout<<"Enter value for row number: "<<x+1<<endl;
    for( j=0;j<col;j++){
        cin>>first[x][j];
    }

}

cout<<"\n\n\nEnter Value For Second Matrix:"<<endl;
for( x=0;x<row;x++){

    cout<<"Enter value for row number: "<<x+1<<endl;

    for( j=0;j<col;j++){
        cin>>second[x][j];

    }

}

// Resultant Matrix
for( x=0;x<row;x++){

    for( j=0;j<col;j++){
        first[x][j]=first[x][j]+second[x][j];

    }

}

cout<<"\n\n\t\tResultant Matrix:"<<endl;
for( x=0;x<row;x++){
    cout<< endl;
    for( j=0;j<col;j++){
        cout<<"\t\t"<<first[x][j]<<"    ";

    }

}
return 0;
}
