#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int i, j, n, k;
    int dp[10001] = {0, };

    cin >> n >> k;

    int coins[n];

    for (i = 0; i < n; i++)
        cin >> coins[i];

    dp[0] = 1;
    for (i = 0; i < n; i++)
        for (j = coins[i]; j <= k; j++)
            if (j >= coins[i])
                dp[j] += dp[j - coins[i]];

    cout << dp[k];
    return 0;
}
