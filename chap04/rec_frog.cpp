#include <iostream>
#include <vector>

using namespace std;

const long long INF = 1LL << 60;

template<class T>
void chmin(T &a, T b) {
    if (a > b) a = b;
}

int N;
vector<int> h;
vector<long long> dp;

long long rec(int i) {
    if (dp[i] < INF) return dp[i];

    if (i == 0)return 0;

    long long res = INF;

    chmin(res, rec(i - 1) + abs(h[i] - h[i - 1]));
    if (i > 1) chmin(res, rec(i - 2) + abs(h[i] - h[i - 2]));

    cout << "dp[" << i << "] = " << res << endl;
    return dp[i] = res;
}

int main() {
    cin >> N;

    h.resize(N);
    for (int i = 0; i < N; ++i) cin >> h[i];

    dp.assign(N, INF);

    cout << rec(N - 1) << endl;
}
