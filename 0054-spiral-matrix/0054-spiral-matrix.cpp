class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();

        int top = 0;
        int left = 0;
        int right = m - 1;
        int bottom = n - 1;

        while (left <= right && top <= bottom) {
            //------>
           if (top <= bottom){
             for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;

           }
           


            // right to bottom

            if (left <= right) {
                 for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;

            }

           

            // bottom right to left
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }


            

            // from bottom to top
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return ans;
    }
};