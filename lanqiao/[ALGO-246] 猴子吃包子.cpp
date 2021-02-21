#include <iostream>
#include <iomanip>
using namespace std;

int main(){

    int x, y, z, x1, y1, z1, p;

    cin >> x >> y >> z >> x1 >> y1 >> z1 >> p;

    double res = 1.0 * x1 / x + 1.0 * y1 / y + 1.0 * z1 / z;

    cout << setiosflags(ios::fixed) << setprecision(p) << fixed << res << endl;

    return 0;
}