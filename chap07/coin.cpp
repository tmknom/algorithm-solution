#include <iostream>
#include <vector>

using namespace std;

const vector<int> value = {500, 100, 50, 10, 5, 1};

int main() {
    int X;
    cin >> X;
    vector<int> a(value.size());
    for (int i = 0; i < value.size(); ++i) cin >> a[i];

    int result = 0;
    for (int i = 0; i < value.size(); ++i) {
        // 枚数制限がない
        int add = X / value[i];

        // 枚数制限を考慮
        if (add > a[i]) add = a[i];

        X -= value[i] * add;
        result += add;

        cout << value[i] << "円 * " << add << "枚" << endl;
    }

    cout << result << endl;
}
