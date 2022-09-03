#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b==0){
        return a;
    }
    return gcd(b, a%b);
}

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        return str1+str2==str2+str1 ? str1.substr(0,gcd(str1.size(),str2.size())) : "";
    }
};

int main(){
    int t;
    cin>>t;
   
    while(t--){
         string s1,s2;
    cin>>s1>>s2;
        Solution ob;
        cout<<ob.gcdOfStrings(s1,s2)<<endl;
    }
    return 0;
}