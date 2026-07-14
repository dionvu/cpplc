#include <string>

using namespace std;

int numberOfSubstrings(string s) {
    int count[3] = {0, 0, 0};
    int n = s.length();
    int res = 0;
    int l = 0;

    for (int r = 0; r < n; r++) {
        count[s[r] - 'a']++;

        while (count[0] && count[1] && count[2]) {
            res += n - r;
            count[s[l] - 'a']--;
            l++;
        }
    }

    return res;
}
