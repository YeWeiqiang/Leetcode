/**
 * 79. 单词搜索 == 面试题12. 矩阵中的路径
 */

class Solution {
public:
    bool dfs(vector<vector<char>>& board, int i, int j, string& word, int start){
        if(board[i][j] != word[start]) return false;
        if(start == word.size()-1) return true;
        int m = board.size();
        int n = board[0].size();

        char temp = board[i][j];
        board[i][j] = 0;
        start += 1;
        if(
                (i > 0 && dfs(board, i-1, j, word, start)) ||
                (i < m-1 && dfs(board, i+1, j, word, start)) ||
                (j > 0 && dfs(board, i, j-1, word, start)) ||
                (j < n-1 && dfs(board, i, j+1, word, start))
                ) return true;
        board[i][j] = temp;

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        if(m == 0) return false;
        int n = board[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(dfs(board, i, j, word, 0)){
                    return true;
                }
            }
        }

        return false;
    }
};