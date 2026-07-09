#include <unordered_map>
#include <string>

using namespace std;

int maxRepOpt1(string text) {
    unordered_map<char, int> freq;
    for (char c : text) freq[c]++;

    int res = 0;

    for (auto [target, _] : freq) {
        int non_targets = 0;
        int l = 0;

        for (int r = 0; r < text.length(); r++) {
            if (text[r] != target) non_targets++;

            while (non_targets > 1) {
                if (text[l] != target) non_targets--;
                l++;
            }

            int wsize = r - l + 1;

            if (!non_targets) {
                res = max(wsize, res);
                continue;
            }

            // Do we have chars outside the window 
            // that we can swap into the window?
            res = max(freq[target] > wsize - 1 ? wsize : wsize - 1, res);
        }
    }

    return res;
}
