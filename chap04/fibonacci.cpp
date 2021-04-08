#include <iostream>

using namespace std;

int fibo(int N) {
    if (N == 0 || N == 1) return N;
    cout << "call fibo(" << N << ")" << endl;

    int result = fibo(N - 1) + fibo(N - 2);
    cout << "return fibo(" << N << ") = " << result << endl;

    return result;
}

int main() {
    cout << fibo(5) << endl;
}
