#include<bits/stdc++.h>
using namespace std;

class Solution{
    public: 
        //Function to return a list of integers denoting spiral traversal of matrix.
        vector<int> spirallyTraverse(vector<vector<int> > a, int r, int c) 
        {
            // code here 
            vector<int>ans;
            int rs=0,re=r-1,cs=0,ce=c-1;
            int nums=r*c;
            int cnt=0;
            while(1){
                for(int i=cs;i<=ce;i++){
                    ans.push_back(a[rs][i]);
                    cnt++;
                }
                rs++;
                if(cnt>=nums){
                    break;
                }
                for(int i=rs;i<=re;i++){
                    ans.push_back(a[i][ce]);
                    cnt++;
                }
                ce--;
                if(cnt>=nums){
                    break;
                }
                for(int i=ce;i>=cs;i--){
                    ans.push_back(a[re][i]);
                    cnt++;
                }
                re--;
                if(cnt>=nums){
                    break;
                }
                for(int i=re;i>=rs;i--){
                    ans.push_back(a[i][cs]);
                    cnt++;
                }
                cs++;
                if(cnt>=nums){
                    break;
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
        vector<vector<int>>a(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        Solution ob;
        vector<int>ans=ob.spirallyTraverse(a,n,m);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}