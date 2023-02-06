#include <iostream>
#include <vector>

using namespace std;

class DisjointSet{
    vector<int> rank, parent;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1); // works with 1 or 0 based indexing
        for(int i=0; i<n; i++){
            parent[i] = i;
        }

    }

    int findPar(int node){
        if(parent[node] == node){ //ultimate parent
            return node;
        }
        return parent[node] = findPar(parent[node]);
        /*
        here parent[node] = this line makes the PATH COMPRESSION possible
        1st time we may take log N, but later on we take only O(1) 
        as we store the ULTIMATE Par in parent arr by that future calls will be O(1) and subcalls also
        */
    }

    void unionByRank(int u, int v){
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);

        if(ulp_u == ulp_v) return; //over

        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else{
            //equal ranks
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++; // as ultimate par of u is made as parent 
        } 
    }

};

int main(){

    DisjointSet ds(7); 
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);

    //we check for same component or not for 3,7
    if(ds.findPar(3) == ds.findPar(7)){
        //ultimate par are same then we say its same component
        cout<<"Same Component\n";
    }
    else{
        cout<<"Not Same Component\n";
    }

    ds.unionByRank(3,7);

    //check again now, after addition of edge
    if(ds.findPar(3) == ds.findPar(7)){
        //ultimate par are same then we say its same component
        cout<<"Same Component\n";
    }
    else{
        cout<<"Not Same Component\n";
    }

    return 0;
}