#include <string>

using namespace std;

int equalSubstring(string s, string t, int maxCost) {
    int res = 0;
    int cost = 0;
    int l = 0;

    for (int r = 0; r < s.length(); r++) {
        cost += abs(s[r] - t[r]);

        while (cost > maxCost) {
            cost -= abs(s[l] - t[l]);
            l++;
        }

        res = max(res, r - l + 1);
    } 

    return res;
}
