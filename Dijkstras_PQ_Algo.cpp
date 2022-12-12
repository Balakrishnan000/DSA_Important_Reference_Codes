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
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        pq.push({0,S}); // dist, node
        
        while(pq.size()>0){
            int d = pq.top().first; // shortest dist from source to node
            int node = pq.top().second;
            pq.pop();
            
            for(auto adjN : adj[node]){
                int adjNode = adjN[0];
                int edgeWeight = adjN[1];
                
                if( d+edgeWeight  < dist[adjNode]){
                    //we got better shortest dist
                    dist[adjNode] = d+edgeWeight;
                    //we put in pq, so that we next select the next min from it
                    pq.push({d+edgeWeight, adjNode});
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