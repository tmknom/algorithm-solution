#include <iostream>
#include <vector>

using namespace std;

string binString(int val) {
    if (!val) return string("0");

    string str;
    while (val != 0) {
        if ((val & 1) == 0) str.insert(str.begin(), '0');
        else str.insert(str.begin(), '1');
        val >>= 1;
    }
    return str;
}

int main() {
    int N;
    cin >> N;

    int W;
    cin >> W;

    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    bool exist = false;
    cout << (1 << N) << endl;
    for (int bit = 0; bit < (1 << N); ++bit) {
        cout << binString(bit) << endl;
        int sum = 0;

        for (int i = 0; i < N; ++i) {
            if (bit & (1 << i)) {
                sum += a[i];
            }
        }

        if (sum == W) {
            exist = true;
        }
    }

    if (exist) cout << "Yes";
    else cout << "No";

    cout << endl;
}
