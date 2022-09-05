#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& a) {
        int n=a.size();
        int sum=0,minlen=INT_MAX,len=0,j=0,i=0;
        for(i=0;i<n;i++){
            sum+=a[i];
            while(sum>=target){
                len=i-j+1;
                minlen=min(len,minlen);
                sum-=a[j];
                j++;
            }
        }
        return minlen==INT_MAX ? 0 : minlen;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,target;
        cin>>n>>target;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        Solution ob;
        cout<<ob.minSubArrayLen(target,a)<<endl;
    }
    return 0;
}