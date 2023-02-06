//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet{
    vector<int> size, parent;
public:
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
        
    }
    
    int findPar(int node){
        if(parent[node] == node)
            return node;
        return parent[node] = findPar(parent[node]); //path compression is there makes O(1)
    }
    
    void unionBySize(int u, int v){
        int ultPu = findPar(u);
        int ultPv = findPar(v);
        
        if(ultPu == ultPv) return; // its already unioned=same component
        
        if(size[ultPu] < size[ultPv]){
            parent[ultPu] = ultPv;
            size[ultPv] += size[ultPu];
        }
        else{
            parent[ultPv] = ultPu;
            size[ultPu] += size[ultPv];
        }
    }
  
};

//Overall TC : O(V+E + 2ELogE + 2E)
#define PIII pair<int,pair<int,int>>
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int sum = 0;
        
        vector<PIII>edges; // wt, u, v fashion
        
        //O(V+E) iterate full adj list
        for(int i=0; i<V; i++){
            for(auto it : adj[i]){
                int v = it[0];
                int wt = it[1];
                
                edges.push_back({wt,{i,v}});
                //we will add 1 edge twice as we havebidirectional edges in adj list
                //but thats completely fine, we can simply put in disjoint set
                //disjoint set simply ignores it. 
                //when ult par are equal we return and skip
            }
        }
        
        //O(2* ELogE) sorting time
        sort(edges.begin(), edges.end());
        DisjointSet ds(V);
        
        //O(2*E*4*alpha) = O(2*E*1) approx 
        for(auto e : edges){
            int wt = e.first;
            int u = e.second.first;
            int v = e.second.second;
            
            int ultPu = ds.findPar(u);
            int ultPv = ds.findPar(v);
            
            if(ultPu != ultPv){
                ds.unionBySize(u,v);
                sum+=wt;
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