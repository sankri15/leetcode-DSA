class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int ans = n * 2;

        sort(reservedSeats.begin(), reservedSeats.end());

        for (int i = 0; i < reservedSeats.size(); i++) {
            int curr = reservedSeats[i][0];

            int flag25 = 1;
            int flag47 = 1;
            int flag69 = 1;

            while (i < reservedSeats.size() &&
                   reservedSeats[i][0] == curr) {

                int seat = reservedSeats[i][1];

                if (seat >= 2 && seat <= 5) {
                    flag25 = 0;

                    if (seat >= 4 && seat <= 5)
                        flag47 = 0;
                }
                else if (seat >= 6 && seat <= 9) {
                    flag69 = 0;

                    if (seat >= 6 && seat <= 7)
                        flag47 = 0;
                }

                i++;
            }

            if (flag69 == 0 && flag25 == 0 && flag47 == 0) {
                ans -= 2;
            }
            else if (flag69 == 0 || flag47 == 0 || flag25 == 0) {
                ans--;
            }

            i--;
        }

        return ans;
    }
};