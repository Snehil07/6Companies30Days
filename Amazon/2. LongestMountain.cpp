#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& a) {
        int n=a.size();
        int cnt=0,maxcnt=0;
        for(int i=1;i<n-1;i++){
            if(a[i]>a[i-1] && a[i]>a[i+1]){
                cnt=1;
                int j=i;
                while(j>0 && a[j]>a[j-1]){
                    j--;
                    cnt++;
                }
                j=i;
                while(j<n-1 && a[j]>a[j+1]){
                    j++;
                    cnt++;
                }
                maxcnt=max(cnt,maxcnt);
            }
        }
        return maxcnt;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        Solution ob;
        cout<<ob.longestMountain(a)<<endl;
    }
    return 0;
}