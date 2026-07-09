#include <vector>

using namespace std;

int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
    int n = customers.size();
    int k = minutes;
    int base = 0;

    for (int i = 0; i < n; i++)
        if (!grumpy[i]) base += customers[i];

    int max_add = 0;
    int add = 0;
    for (int i = 0; i < n; i++) {
        if (grumpy[i]) add += customers[i];

        if (i >= k && grumpy[i - k]) 
            add -= customers[i - k];

        max_add = max(max_add, add);
    }

    return base + max_add;
}
