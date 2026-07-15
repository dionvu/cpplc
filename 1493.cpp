#include <vector>

using namespace std;

int longestSubarray(vector<int>& nums) {
    int zeros = 0;
    int res = 0;
    int l = 0;

    for (int r = 0; r < nums.size(); r++) {
        zeros += !nums[r];

        while (zeros > 1) zeros -= !nums[l++];

        res = max(res, r - l);
    }

    return res;
}
