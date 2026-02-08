class Solution {
public:
    vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
    queue<pair<int ,int>> q;
    unordered_set<string> us, freshO;

    auto key = [&](int x, int y) {
        return to_string(x)+"+"+to_string(y);
    };

    auto markVisited = [&](int x, int y) {
        string str = key(x, y);
        us.insert(str);
        freshO.erase(str);
    };

    auto isSafe = [&](int x, int y) {
        if (x >= 0 && y >= 0 && x < grid.size() && y <grid[0].size()) {
            return true;
        }
        return false;
    };

    for (int i=0;i<grid.size();i++) {
        for (int j=0;j<grid[0].size();j++) {
            if (grid[i][j] == 2) {
                q.push({i,j});
                // grid[i][j] = 0;
                markVisited(i, j);
            } else if (grid[i][j] == 1) {
                freshO.insert(key(i, j));
            }
        }
    }


    int time = -1;
    if (freshO.empty() && us.empty()) return 0;

    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            auto node = q.front();
            q.pop();

            for (int i=0;i<dirs.size();i++) {
                int newX = node.first + dirs[i][0];
                int newY = node.second + dirs[i][1];

                if (isSafe(newX, newY) && !us.contains(key(newX, newY)) && grid[newX][newY] == 1) {
                    markVisited(newX, newY);
                    grid[newX][newY] = 2;
                    q.push({newX, newY});
                }
            }
        }
        time++;
    }
    return freshO.empty() ? time : -1;
    }
};
