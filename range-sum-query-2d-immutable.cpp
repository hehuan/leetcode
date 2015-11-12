//https://leetcode.com/problems/range-sum-query-2d-immutable/
class NumMatrix {
public:
    vector<vector<int>> sum;
    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.size())
        {
            calc(matrix, matrix.size(), matrix[0].size());
        }
    }
    void calc(vector<vector<int>> &matrix, int rowsize, int colsize)
    {
        for (int row=0; row<rowsize; ++row)
        {
            for (int col=0; col<colsize; ++col)
            {
                if (row==0 && col!=0)
                {
                    matrix[0][col] = matrix[0][col] + matrix[0][col-1];
                }
                else if (row!=0 && col==0)
                {
                    matrix[row][0] = matrix[row][0] + matrix[row-1][0];
                }
                else if (row!=0 && col!=0)
                {
                    matrix[row][col] = matrix[row-1][col] + matrix[row][col-1] + matrix[row][col] - matrix[row-1][col-1];
                }
            }
        }
        sum = matrix;
    }
    int sumRegion(int row1, int col1, int row2, int col2)
    {
        if (row1==0 && col1 ==0)
        {
            return sum[row2][col2];
        }
        else if (row1==0)
        {
            return sum[row2][col2] - sum[row2][col1-1];
        }
        else if (col1==0)
        {
            return sum[row2][col2] - sum[row1-1][col2];
        }
        else
        {
            cout << sum[row2][col2] << " " << sum[row1-1][col2] << " " << sum[row2][col1-1] << " " << sum[row2-1][col2-1] << endl;
            return sum[row2][col2] - sum[row1-1][col2] - sum[row2][col1-1] + sum[row1-1][col1-1];
        }
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
