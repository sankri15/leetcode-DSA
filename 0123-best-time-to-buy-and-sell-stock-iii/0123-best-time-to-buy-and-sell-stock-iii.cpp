class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n=v.size();
        vector<int> dp1(n,0);
        vector<int> dp2(n,0);
        int m=v[0],M=0;
        for(int i=1;i<n;i++){
            M=max(M,v[i]-m);
            m=min(v[i],m);
            dp1[i]=M;
        }

        M=v[n-1];
        m=0;
        for(int i=n-2;i>=0;i--){
            m=max(m,M-v[i]);
            M=max(M,v[i]);
            dp2[i]=m;
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum=max(sum,dp1[i]+dp2[i]);
        }   return sum;  
    }
};