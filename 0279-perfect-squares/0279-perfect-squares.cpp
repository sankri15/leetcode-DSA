class Solution {
public:
    int numSquares(int n) {
        while (n%4==0) n/=4;
        if (n%8==7) return 4;
        int sqrt_n=int(sqrt(n));
        vector<int> Squares(sqrt_n, 1);        
        for (int i=2; i<=sqrt_n; i++ ) Squares[i-1]=i*i;
        if (binary_search (Squares.begin(), Squares.end(), n)) return 1;
        for(int x_2:Squares){
            if (binary_search (Squares.begin(), Squares.end(),n-x_2)) return 2;
        }
       
        return 3;
    }
};