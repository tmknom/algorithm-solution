#include <iostream>
#include <vector>

using namespace std;

template<class T>
void chmin(T &a, T b) {
    if (a > b) {
        a = b;
    }
}

const int INF = 1 << 29;

int main() {
    int N;
    cin >> N;

    vector <vector<int>> c(N + 1, vector<int>(N + 1));
    for (int i = 0; i < N + 1; ++i) {
        for (int j = 0; j < N + 1; ++j) {
            cin >> c[i][j];
        }
    }

    vector<int> dp(N + 1, INF);
    dp[0] = 0;

    for (int i = 0; i < N + 1; ++i) {
        for (int j = 0; j < i; ++j) {
            chmin(dp[i], dp[j] + c[j][i]);
        }
    }

    cout << dp[N] << endl;
}
