//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define PII pair<int,int>
//use one more int if u need edges of MST. to store parent.
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> vis(V,0);
        priority_queue<PII, vector<PII>, greater<PII>> pq; // wt, node
        pq.push({0,0}); //{0,0,-1} first no parent, then we have
        int sum = 0;
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int w = it.first;
            int n = it.second;
            
            if(vis[n] == 1)
                continue; // skips from adding to mst and exploring adjs
            
            //not all popped guys contribute to mst. popped unvis guys only
            vis[n] = 1;
            sum+=w;
             
            for(auto adjN : adj[n]){
                int nd = adjN[0];
                int wt = adjN[1];
                
                if(vis[nd] != 1){
                    pq.push({wt,nd});
                }
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends