class Solution {
public:
    int numSteps(string s) {
        int n = s.size(), cnt = 0;
        
        int i = n-1;
        while (i > 0) {
            if (s[i] == '0') {
                cnt++;
                i--;
            } else {
                while (i >= 0 && s[i] == '1') {
                    cnt++;
                    i--;
                }
                if (i>=0) s[i] = '1';
                cnt++;
            }
        }
        return cnt;
    }
};