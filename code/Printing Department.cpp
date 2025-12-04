#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> grid;
    string line;
    while (cin >> line) {
        grid.push_back(line);
    }

    if (grid.empty()) return 0;

    int rows = grid.size();
    int cols = grid[0].size();
    int accessibleCount = 0;
    // Top-Left, Top, Top-Right, Left, Right, Bot-Left, Bot, Bot-Right
    int dr[] = {-1, -1, -1,  0, 0,  1, 1, 1};
    int dc[] = {-1,  0,  1, -1, 1, -1, 0, 1};

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            
            // We only care if the current spot is a paper roll (@)
            if (grid[r][c] == '@') || if(grid[r][c] != '.') {
                int neighborCount = 0;

                for (int i = 0; i < 8; ++i) {
                    int nr = r + dr[i]; 
                    int nc = c + dc[i]; 

                    // we have to stay inside within a limit so.*under the grid.
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                        if (grid[nr][nc] == '@') {
                            neighborCount++;
                        }
                    }
                }
                if (neighborCount < 4) {
                    accessibleCount++;
                }
            }
        }
    }
    cout << "Accessible paper rolls: " << accessibleCount << endl;

    return 0;
}


void part2() {
    vector<string> grid;
    string line;
    while (cin >> line) {
        grid.push_back(line);
    }

    if (grid.empty()) return 0;

    int rows = grid.size();
    int cols = grid[0].size();
    
    
    long long totalRemoved = 0;
    bool somethingChanged = true;

    
    int dr[] = {-1, -1, -1,  0, 0,  1, 1, 1};
    int dc[] = {-1,  0,  1, -1, 1, -1, 0, 1};

    // Now the condition changes, i have to Loop until we can no longer remove any paper
    while (somethingChanged) {
        somethingChanged = false;
      
        vector<pair<int, int>> toRemove;

        // Scan the grid
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                
                // Only check existing paper rolls
                if (grid[r][c] == '@') || (grid[r][c] !='.') {
                    int neighborCount = 0;
                    for (int i = 0; i < 8; ++i) {
                        int nr = r + dr[i];
                        int nc = c + dc[i];

                        
                        if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                            if (grid[nr][nc] == '@') {
                                neighborCount++;
                            }
                        }
                    }

                    // If fewer than 4 neighbors, mark for removal
                    if (neighborCount < 4) {
                        toRemove.push_back({r, c});
                    }
                }
            }
        }
        if (!toRemove.empty()) {
            somethingChanged = true;
            totalRemoved += toRemove.size();

            // Update the grid (turn '@' into '.')
            for (auto p : toRemove) {
                grid[p.first][p.second] = '.';
            }
        
        }
    }
    cout << "Total rolls of paper removed: " << totalRemoved << endl;

    return 0;
}
