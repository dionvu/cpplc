#include <numeric>
#include <vector>

using namespace std;

int minOperations(vector<int>& nums, int x) {
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    int res = -1;
    int l = 0;

    for (int r = 0; r < nums.size(); r++) {
        sum -= nums[r];

        while (l <= r && sum < x) sum += nums[l++];

        if (sum == x) res = max(res, r - l + 1);
    }

    return res != -1 ? nums.size() - res : -1;
}
