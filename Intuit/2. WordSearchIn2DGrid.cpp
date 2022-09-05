#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        bool dfs(vector<vector<char>>& board,string &word,vector<vector<int>>&vis,int i,int j,int indx,int dX[],int dY[]){
            if(indx==word.length()){
                return true;
            }
            vis[i][j]=1;
            for(int k=0;k<4;k++){
                int nr=i+dX[k];
                int nc=j+dY[k];
                int n=board.size();
                int m=board[0].size();
                if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0 and board[nr][nc]==word[indx]){
                    if(dfs(board,word,vis,nr,nc,indx+1,dX,dY)){
                        return true;
                    }
                }
            }
            vis[i][j]=0;
            return false;
        }
        bool isWordExist(vector<vector<char>>& board, string word) {
            int n=board.size();
            int m=board[0].size();
            vector<vector<int>>vis(n,vector<int>(m,0));
            int dX[]={-1,0,1,0,};
            int dY[]={0,1,0,-1,};
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(board[i][j]==word[0]){
                        if(dfs(board,word,vis,i,j,1,dX,dY)){
                            return true;
                        }
                    }
                }
            }
            return false;
        }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>>board(n,vector<char>(m,'*'));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>board[i][j];
            }
        }
        string word;
        cin>>word;
        Solution ob;
        bool ans=ob.isWordExist(board,word);
        if(ans){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}