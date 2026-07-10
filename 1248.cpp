#include <vector>

using namespace std;

int numberOfSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    int l = 0;
    int odds = 0;
    int res = 0;

    for (int r = 0; r < n; r++) {
        odds += nums[r] % 2;

        while (odds > k) {
            odds -= nums[l] % 2;
            l++;
        }

        if (odds == k) {
            int missed = 0;
            int i = l;

            while (i < r && nums[i] % 2 == 0) {
                missed++;
                i++;
            }

            res += missed + 1;
        }
    }

    return res;
}
