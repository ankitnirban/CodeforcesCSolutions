
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int n = atoi(argv[1]);
    int s = atoi(argv[2]);
    int r = atoi(argv[3]);
    int mct = atoi(argv[4]);
    cout << mct + 1 << '\n' << n << ' ' << s << '\n';
    for (int i = 0; i < n; i++){
        cout << -r << " \n"[i == n - 1];
    }
    for (int i = 0; i < mct; i++){
        cout << "1 987456328\n-987800000\n";
    }

}