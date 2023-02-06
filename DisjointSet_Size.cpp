#include <iostream>
#include <vector>

using namespace std;

class DisjointSet{
    vector<int> size, parent;
public:
    DisjointSet(int n){
        size.resize(n+1,0);
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

    // change is ONLY HERE compared to UnionbyRANK
    void unionBySize(int u, int v){
        int ulp_u = findPar(u); //ultimate parent - par's par's par till no more par
        int ulp_v = findPar(v);

        if(ulp_u == ulp_v) return; //over

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v; // bigger is parent ultimately
            size[ulp_v]+=size[ulp_u]; //size of v increase as u is attached to v
        }
        else{
            parent[ulp_v] = ulp_u; // bigger is parent ultimately
            size[ulp_u]+=size[ulp_v]; //size of u increase as v is attached to u
        }
    }

};

int main(){

    DisjointSet ds(7); 
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);

    //we check for same component or not for 3,7
    if(ds.findPar(3) == ds.findPar(7)){
        //ultimate par are same then we say its same component
        cout<<"Same Component\n";
    }
    else{
        cout<<"Not Same Component\n";
    }

    ds.unionBySize(3,7);

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

/*
- rank is distorted at PATH Compression
- so go to size
- we always connect the SMALLER Size/Rank to LARGAER Size/Rank.
- Why? Bcoz to maintain the height and make sure while finding parent we dont exceed log N
- Oppositely if we connect, then it leads to huge longer path unnessasary time waste in traversal 

- DONT USE UNION by rank and size MIXED.

*/

/*
By RANK TC: O(4*alpha) = as goood as O(1)
By SIZE TC: O(4*alpha) = as goood as O(1)
As in both methods - idea wise only we make difference, no diff complexities wise
*/