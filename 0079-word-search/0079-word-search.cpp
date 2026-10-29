class Solution {
public:
    int dr[4]={0,0,1,-1};
    int dc[4]={1,-1,0,0};
    bool soln(vector<vector<char>>&board,int i,int n,int j,int m,string&word,int idx){
       
        if(i<0||j<0||i>=n||j>=m) return false;
        if(board[i][j]!=word[idx]) return false;
         if(idx==word.length()-1) return true;
        char temp=board[i][j];
        board[i][j]='%';


        for(int k=0;k<4;k++){
            int newr=i+dr[k];
            int newc=j+dc[k];
            if (soln(board, newr,n, newc,  m, word, idx + 1)){
                board[i][j]=temp;
            return true;
            }

        }
        board[i][j]=temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool flag=false;
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(word[0]==board[i][j]){
                    if(soln(board,i,n,j,m,word,0)){return true;}
                   
                }
              
            }
        }
        return false;
    }
};