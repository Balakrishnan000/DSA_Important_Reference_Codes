//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define PII pair<int,int>
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dist(V, 1e9); // 1e9 big val with no overflow
        dist[S] = 0;
        set<PII> st;
        st.insert({0,S});
        
        while(st.size()>0){
            // *(iter) - gives val pointed by it, that is pair here
            //begin is min most guy - as set keeps in ASC order
            int d = (*(st.begin())).first; // shortest dist from source to node
            int node = (*(st.begin())).second; // Finalized node
            
            st.erase(st.begin());
            
            for(auto adjN : adj[node]){
                int adjNode = adjN[0];
                int edgeW = adjN[1];
                
                //till node - shortest is d + edgeW (node to adjNode)< already stored then update
                
                if(d + edgeW < dist[adjNode]){
                    //update it as we got better ans
                    //push into set so that adjNode gets finalized afterwards
                    if(dist[adjNode] != 1e9){
                        //its not first time, already set push happened
                        //now we do decrease key - that is delete old guy and push new guy
                        //this does not happen in PQ, no erase ops
                        //dist[adjNode], adjNode - is old pushed one
                        st.erase({dist[adjNode], adjNode}); //logn ops
                        dist[adjNode] = d + edgeW; // now updated
                        st.insert({dist[adjNode], adjNode}); // updated val - logn ops
                    }
                    else{
                        //now its first time, so no decrease key or del needed
                        dist[adjNode] = d + edgeW; // now updated
                        st.insert({dist[adjNode], adjNode}); // updated val - logn ops
                    }
                    //by investing logn we saved few operations of relaxations in future
                }
            }
            
                
        }
            
        
        return dist;
        //no need of vis, in case of fully positive edge weights
        //as d + someval will never be less than dist[] 
        //eg - 1 d= 4 1-2 edge w = 2
        // so for node 2 d is 4+2 = 6
        // now try to relax node 1 from 2.
        // we simply 6 + 2 = 8 < 4 BIG NO Always as the 8 came from 4 + 2 + 2
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends