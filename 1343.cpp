#include <vector>

using namespace std;

int numOfSubarrays(vector<int>& arr, int k, int threshold) {
    int min_sum = threshold * k;
    int sum = 0;
    int res = 0;

    for (int r = 0; r < arr.size(); r++) {
        sum += arr[r];

        if (r < k - 1) continue;

        if (sum >= min_sum) res++;

        sum -= arr[r - k + 1];
    }

    return res;
}
