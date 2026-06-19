// Example 1:


// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// Output: true
// Example 2:


// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
// Output: true
// Example 3:


// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
// Output: false
 

// Constraints:

// m == board.length
// n = board[i].length
// 1 <= m, n <= 6
// 1 <= word.length <= 15
// board and word consists of only lowercase and uppercase English letters.

bool dfs(char** board, int boardSize, int* boardColSize,int i,int j, char* word,int idx){
    if(word[idx]=='\0')return true;
    
    if(i<0 || i>=boardSize || j<0 || j>=boardColSize[i] || board[i][j]!=word[idx])return false;

    char temp=board[i][j];
    board[i][j]='#';
    bool found=(dfs(board,boardSize,boardColSize,i+1,j,word,idx+1) ||
                dfs(board,boardSize,boardColSize,i,j+1,word,idx+1) ||
                dfs(board,boardSize,boardColSize,i-1,j,word,idx+1) ||
                dfs(board,boardSize,boardColSize,i,j-1,word,idx+1));

    board[i][j]=temp;
    return found;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardColSize[i];j++){
            if(dfs(board,boardSize,boardColSize,i,j,word,0))return true;
        }
    }
    return false;
}