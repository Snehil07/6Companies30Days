#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool winnerOfGame(string colors) {
        int n=colors.length();
        int a=0,b=0;
        for(int i=1;i<n-1;i++){
            if(colors[i-1]==colors[i] && colors[i]==colors[i+1]){
                if(colors[i]=='A'){
                    a++;
                }
                else{
                    b++;
                }
            }
        }
        if(a==0 || b>=a){
            return false;
        }
        return true;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        Solution ob;
        bool ans=ob.winnerOfGame(s);
        if(ans){
            cout<<"Alice Wins"<<endl;
        }
        else{
            cout<<"Bob Wins"<<endl;
        }
    }
}