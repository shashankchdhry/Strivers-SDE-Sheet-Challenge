/**
    * @author: shashankchdhry
    * @made:   2023-06-11 05:14:49 
**/
#include <bits/stdc++.h>
#define ll long long int
#define nline "\n"
    
using namespace std;
    
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> matrix = {{0,1,2,0}, {3,4,5,2}, {1,3,1,5}};
    
    Solution solution = Solution();
    solution.setZeroes(matrix);
    
    return 0;
}

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();

        bool rflag = false, cflag = false;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (matrix[i][j] == 0) {
                    if (i == 0)
                        rflag = true;
                    if (j == 0)
                        cflag = true;
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < r; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < c; j++)
                    matrix[i][j] = 0;
            }
        }

        for (int j = 1; j < c; j++) {
            if (matrix[0][j] == 0)
                for (int i = 1; i < r; i++)
                    matrix[i][j] = 0;
        }
        if (rflag)
            for (int j = 0; j < c; j++) 
                matrix[0][j] = 0;
            
        if (cflag)
            for (int i = 0; i < r; i++)
                matrix[i][0] = 0;
    }
};