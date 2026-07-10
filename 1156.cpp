#include <string>
#include <unordered_map>

using namespace std;

int maxRepOpt1(string text) {
    unordered_map<char, int> freq;
    for (char c : text) freq[c]++;

    int res = 0;

    for (auto [target, _] : freq) {
        int nontargets = 0;
        int l = 0;

        for (int r = 0; r < text.length(); r++) {
            nontargets += text[r] != target;

            while (nontargets > 1) {
                nontargets -= text[l] != target;
                l++;
            }

            int wsize = r - l + 1;

            if (!nontargets) {
                res = max(res, wsize);
                continue;
            }

            res = max(freq[target] > wsize - 1 ? wsize : wsize - 1, res);
        }
    }

    return res;
}
