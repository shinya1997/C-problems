#include <iostream>
#include <vector>
using namespace std;

vector<int> Array_tmp(int bit, int N) {
    vector<int> array_tmp;
    for (int i = 0; i < N; ++i) {
        if (bit & (1 << i)) {
            array_tmp.push_back(i);
        }
    }
    cout << "bit" << bit << "= {";
    for(int i = 0; i < array_tmp.size(); i++)
        cout << array_tmp.at(i) << " ";
    cout << "}" << endl;
    return array_tmp;
}

int main() {
    int N, W;
    cin >> N >> W;
    vector<int> array(N);
    for (int i = 0; i < N; ++i)
        cin >> array[i];
    bool exist = false;
    for (int bit = 0; bit < (1 << N); ++bit) {
        vector<int> S = Array_tmp(bit, N);
        int sum = 0;
        for (int i : S)
            sum += array[i];
        if (sum == W)
            exist = true;
    }

    if (exist)
        cout << "Yes!" << endl;
    else
        cout << "No" << endl;
    return 0;
}
