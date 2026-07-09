#include <vector>

using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int zeros = 0;
    int res = 0;
    int l = 0;

    for (int r = 0; r < nums.size(); r++) {
        if (!nums[r]) zeros++;

        while (zeros > k) {
            if (!nums[l]) zeros--;
            l++;
        }

        res = max(res, r - l + 1);
    }

    return res;
}
