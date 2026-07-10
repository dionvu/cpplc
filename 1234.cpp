#include <string>
#include <unordered_map>

using namespace std;

int balancedString(string s) {
    unordered_map<char, int> freq;
    int n = s.length();
    int target = n / 4;
    int over = 0;
    int res = n;
    int l = 0;

    for (char c : s) freq[c]++;

    for (char c : {'Q', 'W', 'E', 'R'})
        if (freq[c] > target) over++;

    if (over == 0) return 0;

    for (int r = 0; r < n; r++) {
        char c = s[r];

        if (freq[c] == target + 1) over--;
        freq[c]--;

        while (over == 0) {
            res = min(res, r - l + 1);
            char cl = s[l];

            freq[cl]++;
            if (freq[cl] == target + 1) over++;

            l++;
        }
    }
    return res;
}
