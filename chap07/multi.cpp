#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector <Interval> A(N), B(N);
    for (int i = 0; i < A.size(); ++i) cin >> A[i] >> B[i];

    int sum = 0;
    for (int i = N - 1; i >= 0; --i) {
        A[i] += sum;
        int amari = A[i] % B[i];
        int D = 0;
        if (amari != 0) D = B[i] - amari;
        sum += D;
    }

    cout << sum << endl;
}
