#include <numeric>
#include <vector>

using namespace std;

int maxScore(vector<int>& cardPoints, int k) {
    int sum = std::accumulate(cardPoints.begin(), cardPoints.end(), 0);
    int wsize = cardPoints.size() - k;
    int res = 0;

    for (int r = 0; r < cardPoints.size(); r++) {
        sum -= cardPoints[r];

        if (r >= wsize) sum += cardPoints[r - wsize];

        if (r >= wsize - 1) res = max(res, sum);
    }

    return res;
}
