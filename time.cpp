#include <bits/stdc++.h>    //12:40:22AM

using namespace std;
typedef long long ll;


string timeConversion(string s) {

    int pos = s.find(":");
    string sub = s.substr(pos + 1);     //contains the string 05:45PM
    string sub1 = s.substr(0 , pos);    //contains the string 07
    string sub2 = sub.substr(pos+1);    //contains the string 45PM
    // cout<<sub<<"\n"<<sub1<<"\n"<<sub2<<"\n";
    // cout<<sub2.length();
    for(int i=0;i<4;i++){
        if((sub2[i]=='P' ||sub2[i]=='p') && (sub2[i+1]=='M' ||sub2[i+1]=='m')){
            ll x = stoll(sub1,nullptr,10);
            if(x==12){
                string str=to_string(x);
                sub = sub.erase(5,6);
                string ss = str + ":"+ sub;
                cout<<ss<<"\n";
            }
            else{x+=12;
            string str = to_string(x);
            sub = sub.erase(5,6);
            string ss = str + ":"+ sub;
            cout<<ss<<"\n";
            }
        }
        // if((sub2[i]=='A' ||sub2[i]=='a') && (sub2[i+1]=='M' ||sub2[i+1]=='m')){
        //     sub=sub.erase(5,6);
        //     string ss= sub1+ ":" + sub;
        //     cout<<ss<<"\n";
        // }
        if((sub2[i]=='A' ||sub2[i]=='a') && (sub2[i+1]=='M' ||sub2[i+1]=='m')){
            ll x = stoll(sub1,nullptr,10);
            string str;
            if(x==12){
                x-=12;
                str = to_string(x);
                str=str+ "0";
                sub=sub.erase(5,6);
                string ss= str + ":" + sub;
                cout<<ss<<"\n";
            }
            else{
                sub=sub.erase(5,6);
                string ss= sub1+ ":" + sub;
                cout<<ss<<"\n";
            }
            
        }
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
