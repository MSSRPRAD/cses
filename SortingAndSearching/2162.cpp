#include <bits/stdc++.h>

using namespace std;

// 1 2 3 4 5 6 7 8 9 10

int main() {
    int n;

    // Read the value of n
    cin >> n;

    deque<int> q;
    for (int i = 1; i <= n; i++) q.push_back(i);

    bool flag = false;
    while (!q.empty()) {
        if (flag) {
            // Remove front of queue
            int front = q.front();
            cout << front << " ";
            q.pop_front();
        } else {
            int front = q.front();
            q.pop_front();
            q.push_back(front);
        }
        flag = !flag;
    }

    return 0;
}
