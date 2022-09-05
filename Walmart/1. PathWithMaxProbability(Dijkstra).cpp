#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        priority_queue<pair<double,int>>pq;
        vector<double>dist(n,0);
        vector<pair<int,double>>v[n];
        for(int i=0;i<edges.size();i++){
            int x=edges[i][0];
            int y=edges[i][1];
            double w=succProb[i];
            v[x].push_back({y,w});
            v[y].push_back({x,w});
        }
        pq.push({1,start});
        while(!pq.empty()){
            auto curr=pq.top();
            double currprob=curr.first;
            int currnode=curr.second;
            pq.pop();
            for(auto j:v[currnode]){
                int neighbour=j.first;
                double neighbourprob=j.second;
                if(dist[neighbour]<(currprob*neighbourprob)){
                    dist[neighbour]=currprob*neighbourprob;
                    pq.push({dist[neighbour],neighbour});
                }
            }
        }
        return dist[end];
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,e;
        cin>>n>>e;
        vector<vector<int>>edges(e);
        vector<double>succProb(e);
        int start,end;
        for(int i=0;i<e;i++){
            int x,y;
            double prob;
            cin>>x>>y;
            cin>>prob;
            edges[i].push_back(x);
            edges[i].push_back(y);
            succProb[i]=prob;
        }
        cin>>start>>end;
        Solution ob;
        double ans=ob.maxProbability(n,edges,succProb,start,end);
        cout<<ans<<endl;
    }
}