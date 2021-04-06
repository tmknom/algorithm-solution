#include <iostream>
#include <vector>

using namespace std;
const int INF = INT_MAX;

int main() {
    int N;
    cin >> N;

    int K;
    cin >> K;

    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    vector<int> b(N);
    for (int i = 0; i < N; ++i) cin >> b[i];

    int min_value = INF;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int sum = a[i] + b[j];
            if (sum < K) {
                continue;
            }
            if (sum < min_value) {
                min_value = sum;
            }
        }
    }

    cout << min_value << endl;
}
