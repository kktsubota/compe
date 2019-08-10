#include <pair>
#include <utility>
#include <algorithm>

class Solution {
public:
    bool isRobotBounded(string instructions) {
        // exec 4 times
        int x = 0;
        int y = 0;
        int direction = 0;
        for (int i = 0; i < 4; i++) {
            for (auto inst: instructions) {
                if (inst == 'G') {
                    if (direction == 0) {
                        y += 1;
                    } else if (direction == 1) {
                        x += 1;
                    } else if (direction == 2) {
                        y -= 1;
                    } else {
                        x -= 1;
                    }
                } else if (inst == 'L') {
                    direction -= 1;
                    direction = (direction + 4) % 4;
                } else if (inst == 'R') {
                    direction += 1;
                    direction = direction % 4;
                }
            }
        }
        if (x == 0 && y == 0) {
            return true;
        } else {
            return false;
        }
    }
};