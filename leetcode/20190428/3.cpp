#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>


void printVector(std::vector<int>& v) {
    for (auto elem: v) {
        std::cout << elem << ",";
    }
    std::cout << std::endl;
}


void printMatrix(std::vector<std::vector<int>>& mat) {
    for (auto row: mat) {
        printVector(row);
    }
}

class Solution {
private:
    std::vector<std::vector<int>> countTable;
public:
    int maxUncrossedLines(std::vector<int>& A, std::vector<int>& B) {
        std::unordered_map<int, std::vector<int>> Bdict;
        for (int i = 0; i < B.size(); i++) {
            Bdict[B[i]].push_back(i);
        }
        for (int i = 0; i < A.size(); i++) {
            std::vector<int> countRow(B.size(), -1);
            this->countTable.push_back(countRow);
        }
        // printMatrix(this->countTable);
        int ans = count(A, Bdict, 0, 0);
        // printMatrix(this->countTable);
        return ans;
    }

    int count(std::vector<int>& A, std::unordered_map<int, std::vector<int>>& Bdict, int indexA, int indexB) {
        if (indexA >= this->countTable.size() || indexB >= this->countTable[0].size()) {
            return 0;
        }
        // 1. A[i] does not matches with B
        // std::cout << indexA << ", " << indexB << std::endl;
        if (this->countTable[indexA][indexB] != -1) {
            return this->countTable[indexA][indexB];
        }
        int best = count(A, Bdict, indexA + 1, indexB);

        // 2. try to match A[i] with B
        std::vector<int> Bindices = Bdict[A[indexA]];
        // std::cout << "Bindices: ";
        // printVector(Bindices);
        if (Bindices.size() == 0) {
            this->countTable[indexA][indexB] = best;
            return best;
        }
        auto index_ptr = std::lower_bound(Bindices.begin(), Bindices.end(), indexB);
        // not found
        if (index_ptr == Bindices.end()) {
            this->countTable[indexA][indexB] = best;
            return best;
        } else {
            // match A[i] with Bindices[index] of B
            int index = std::distance(Bindices.begin(), index_ptr);
            // std::cout << "index: " << index << std::endl;
            best = std::max(best, 1 + count(A, Bdict, indexA + 1, Bindices[index] + 1));
            this->countTable[indexA][indexB] = best;
        }
        return best;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol = Solution();
    // std::vector<int> A = {1, 4, 2};
    // std::vector<int> B = {1, 2, 4};
    // std::vector<int> A = {3, 3};
    // std::vector<int> B = {3};
    std::vector<int> A = {2, 5, 1, 2, 5};
    std::vector<int> B = {10, 5, 2, 1, 5, 2};

    int ans = sol.maxUncrossedLines(A, B);
    std::cout << ans << std::endl;
    return 0;
}
