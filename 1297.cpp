#include <string>
#include <unordered_map>

using namespace std;

int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
    unordered_map<string, int> occurances;
    unordered_map<char, int> count;
    int res = 0;

    for (int r = 0; r < s.length(); r++) {
        count[s[r]]++;

        if (r < minSize - 1) continue;

        if (count.size() <= maxLetters) 
            occurances[s.substr(r - minSize + 1, minSize)]++;

        int lc = s[r - minSize + 1];
        if (--count[lc] == 0) count.erase(lc);
    }

    for (auto [_, v] : occurances) res = max(res, v);

    return res;
}
