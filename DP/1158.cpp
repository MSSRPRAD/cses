#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> prices(n);
    for (int i = 0; i < n; i++)
        cin >> prices[i];

    vector<int> pages(n);
    for (int i = 0; i < n; i++)
        cin >> pages[i];

    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));

    // dp[i][j] = max pages possible under i rupees and 

    cout << dp[x] << endl;
    return 0;
}
