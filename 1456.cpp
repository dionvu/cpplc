#include <string>
#include <unordered_set>

using namespace std;

int maxVowels(string s, int k) {
    unordered_set<char> vowels{ 'a', 'e', 'i', 'o', 'u' };
    int count = 0;
    int res = 0;

    for (int r = 0; r < s.length(); r++) {
        count += vowels.contains(s[r]);

        if (r >= k) count -= vowels.contains(s[r - k]);

        if (r >= k - 1) res = max(res, count);
    }

    return res;
}
