#include <iostream>
#include <vector>

using namespace std;

vector<long> memo;

long fibo(int N) {
    cout << "call fibo(" << N << ")" << endl;
    if (N == 0 || N == 1) return N;

    if (memo[N] != -1) return memo[N];

    memo[N] = fibo(N - 1) + fibo(N - 2);
    cout << "return fibo(" << N << ") = " << memo[N] << endl;

    return memo[N];
}

int main() {
    memo.assign(50, -1);
    fibo(49);

    for (int i = 2; i < 50; ++i) {
        cout << "fibo(" << i << ") = " << memo[i] << endl;
    }
}
