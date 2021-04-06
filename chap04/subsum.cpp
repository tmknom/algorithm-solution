#include <iostream>
#include <vector>

using namespace std;

bool func(int i, int sum, const vector<int> &a) {
    cout << "call func(" << i << ", " << sum << ", a)" << endl;
    if (i == 0) {
        if (sum == 0) return true;
        else return false;
    }

    // a[i-1]を選ばない場合
    if (func(i - 1, sum, a)) {
        cout << "return func(" << i - 1 << ", " << sum << ", a) = true" << endl;
        return true;
    }

    // a[i-1]を選ぶ場合
    if (func(i - 1, sum - a[i - 1], a)) {
        cout << "return func(" << i - 1 << ", " << (sum - a[i - 1]) << ", a) = true" << endl;
        return true;
    }

    return false;
}

int main() {
    int N, sum;
    cin >> N >> sum;

    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    if (func(N, sum, a)) cout << "Yes" << endl;
    else cout << "No" << endl;
}
