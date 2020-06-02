#include <vector>
#include <iostream>
#include <any>

void printGrid(std::vector<std::vector<int>> v) {
    for (auto row: v) {
        for (auto elem: row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}
class Solution {
public:
    std::vector<std::vector<int>> colorBorder(std::vector<std::vector<int>>& grid, int r0, int c0, int color) {
        // get a region
        std::vector<std::vector<bool>> group;
        for (int i = 0; i < grid.size(); i++) {
            std::vector<bool> group_row(grid[i].size(), false);
            group.push_back(group_row);
        }
        this->groupRegions(grid, group, r0, c0);
        // get borders
        std::vector<std::vector<bool>> colorize = group;
        for (int r = 0; r < group.size(); r++) {
            for (int c = 0; c < group[0].size(); c++) {
                if (!group[r][c]) {
                    continue;
                }                
                if (this->is_surrounded(group, r, c)) {
                    colorize[r][c] = false;
                }
            }
        }
        for (int r = 0; r < group.size(); r++) {
            for (int c = 0; c < group[0].size(); c++) {
                if (colorize[r][c]) {
                    grid[r][c] = color;
                }
            }
        }
        return grid;
    }

    void groupRegions(std::vector<std::vector<int>>& grid, std::vector<std::vector<bool>>& group, int r, int c) {
        int color = grid[r][c];
        if (group[r][c]) {
            return;
        }
        group[r][c] = true;
        if (r - 1 >= 0) {
            if (grid[r - 1][c] == color) {
                groupRegions(grid, group, r - 1, c);
            }
        }
        if (c - 1 >= 0) {
            if (grid[r][c - 1] == color) {
                groupRegions(grid, group, r, c - 1);
            }            
        }
        if (r + 1 < grid.size()) {
            if (grid[r + 1][c] == color) {
                groupRegions(grid, group, r + 1, c);
            }
        }
        if (c + 1 < grid[0].size()) {
            if (grid[r][c + 1] == color) {
                groupRegions(grid, group, r, c + 1);
            }            
        }
        return;
    }

    bool is_surrounded(std::vector<std::vector<bool>>& group, int r, int c) {
        if (r - 1 >= 0) {
            if (!group[r - 1][c]) {
                return false;
            }
        } else {
            return false;
        }
        if (r + 1 < group.size()) {
            if (!group[r + 1][c]) {
                return false;
            }
        } else {
            return false;
        }
        if (c - 1 >= 0) {
            if (!group[r][c - 1]) {
                return false;
            }
        } else {
            return false;
        }
        if (c + 1 < group[0].size()) {
            if (!group[r][c + 1]) {
                return false;
            }
        } else {
            return false;
        }
        return true;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol = Solution();
    std::vector<std::vector<int>> grid;
    int r0 = 4;
    int c0 = 4;
    int color = 3;
    for (int i = 0; i < 5; i++) {
        std::vector<int> grid_row;
        if (i == 0) {
            grid_row = {2, 1, 3, 2, 1, 1, 2};
        } else if (i == 1) {
            grid_row = {1, 2, 3, 1, 2, 1, 2};
        } else if (i == 2) {
            grid_row = {1, 2, 1, 2, 2, 2, 2};
        } else if (i == 3) {
            grid_row = {2,1,2,2,2,2,2};
        } else {
            grid_row = {2,3,3,3,2,1,2};
        }
        grid.push_back(grid_row);
    }
    // printGrid(grid);
    // std::cout << std::endl;

    // [[2,1,3,2,1,1,2],[1,2,3,1,2,1,2],[1,2,1,2,2,2,2],[2,1,2,2,2,2,2],[2,3,3,3,2,1,2]]
    auto out = sol.colorBorder(grid, r0, c0, color);
    // printGrid(out);
    return 0;
}
