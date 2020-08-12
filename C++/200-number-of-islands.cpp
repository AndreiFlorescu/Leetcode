class Solution {
public:
    bool outOfBounds(int x, int y, int n, int m) {
        if (x < 0 || x >= n || y < 0 || y >= m) {
            return true;
        }
        
        return false;
    }
    
    void lee(int x, int y, vector<vector<char>>& grid) {
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        
        int no_dir = 4;
        
        const int n = grid.size();
        const int m = grid[0].size();
        
        queue<pair<int, int>> q;
        
        q.push({x, y});
        grid[x][y] = '0';
        
        while (!q.empty()) {
            
            int cur_x = q.front().first;
            int cur_y = q.front().second;
            
            q.pop();
            
            for (int i = 0; i < no_dir; i++) {
                int vec_x = cur_x + dx[i];
                int vec_y = cur_y + dy[i];
                
                if (outOfBounds(vec_x, vec_y, n, m)) {
                    continue;
                }
                
                if (grid[vec_x][vec_y] == '1') {
                    grid[vec_x][vec_y] = '0';
                    
                    q.push({vec_x, vec_y});
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        const int n = grid.size();
        
        if (n == 0) {
            return 0;
        }
        
        const int m = grid[0].size();
        
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    lee(i, j, grid);
                    ans++;
                }
            }
        }
        
        return ans;
    }
};