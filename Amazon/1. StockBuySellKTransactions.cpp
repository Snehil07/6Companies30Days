#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxProfit(int k, int n, int a[]) {
        // code here
        int dp[k+1][n];
        for(int i=0;i<n;i++){
            dp[0][i]=0;
        }
        for(int i=0;i<=k;i++){
            dp[i][0]=0;
        }
        for(int i=1;i<=k;i++){
            int maxx=INT_MIN;
            for(int j=1;j<n;j++){
                int curr=dp[i][j-1];
                int currmax=dp[i-1][j-1]-a[j-1];
                if(maxx<currmax){
                    maxx=currmax;
                }
                curr=max(curr,maxx+a[j]);
                // for(int k=0;k<j;k++){
                //     int prevdayans=dp[i-1][k];
                //     int prof=a[j]-a[k];
                //     if(prof+prevdayans > curr){
                //         curr=prof+prevdayans;
                //     }
                // }
                dp[i][j]=curr;
            }
        }
        return dp[k][n-1];
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>k>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        Solution ob;
        cout<<ob.maxProfit(k,n,a)<<endl;
    }
    return 0;
}