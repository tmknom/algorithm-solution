#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<long> F(50);
    F[0] = 0, F[1] = 1;
    for (int i = 2; i < 50; ++i) {
        F[i] = F[i - 1] + F[i - 2];
        cout << "F[" << i << "] = " << F[i] << endl;
    }
}
