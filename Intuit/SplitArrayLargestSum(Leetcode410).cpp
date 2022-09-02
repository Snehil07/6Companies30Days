#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& a, int n, int mid, int m){
        int sum=0;
        int num=1;
        for(int i=0;i<n;i++){
            sum+=a[i];
            if(sum>mid){
                sum=a[i];
                num++;
            }
        }
        return m>=num;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int n=nums.size();
        long long sum=0;
        int maxx=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            maxx=max(maxx,nums[i]);
        }
        int low=maxx;
        int high=sum;
        int ans=sum;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(nums,n,mid,m)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        Solution ob;
        cout<<ob.splitArray(a,m)<<endl;
    }
    return 0;
}