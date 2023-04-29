#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int bfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& vis){
    int sum = grid[r][c];
    queue<pair<int,int>> qu;
    qu.push({r,c});
    vis[r][c] = 1;
    int N = grid.size();
    int M = grid[0].size();
    
    while(!qu.empty()){
        auto it = qu.front();
        qu.pop();
        int row = it.first;
        int col = it.second;
        //cout<<row<<" "<<col<<"\n";
        
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        
        for(int i=0; i<4; i++){
            int nr = row + dr[i];
            int nc = col + dc[i];
            
            if(nr>=0 && nr<N && nc>=0 && nc<M && vis[nr][nc] != 1 && grid[nr][nc] != 0){
                vis[nr][nc] = 1;
                sum += grid[nr][nc];
                qu.push({nr,nc});
            }
        }
        
    }
    //cout<<"\n";
    return sum;
}

int main(){
    vector<vector<int>> grid(5, vector<int>(6, 100));

    int N = grid.size();
    int M = grid[0].size();
    vector<vector<int>> vis(N, vector<int>(M, 0));
    
    int max_val = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(grid[i][j]!=0 && vis[i][j] == 0){
                int s = bfs(i,j,grid,vis);
                max_val = max(max_val, s);
            }
        }
    }
    return 0;
}