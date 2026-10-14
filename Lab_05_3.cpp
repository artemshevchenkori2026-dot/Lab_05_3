// -2 2 10
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Допоміжна функція z(x)
double z(const double x) {
    if (abs(x) >= 1) {
        return (sin(x) + 1.0) / (pow(cos(x), 2) + exp(x));
    }
    else {
        double S = 0;
        int k = 0;
        double a = 1.0; // перший доданок при k = 0
        S = a;

        do {
            k++;
            double R = (2.0 * x) / k; // коефіцієнт рекурентності
            a *= R;
            S += a;
        } while (k < 6); // сума від k = 0 до k = 6 включно

        return (1.0 / exp(x * x)) * S;
    }
}

int main() {
    double pp, pk, dp, y;
    int n;

    cout << "pp = "; cin >> pp;
    cout << "pk = "; cin >> pk;
    cout << "n = ";  cin >> n;

    dp = (pk - pp) / n;

    cout << fixed;
    cout << "---------------------------" << endl;
    cout << "|" << setw(10) << "p" << " |"
        << setw(12) << "y" << " |" << endl;
    cout << "---------------------------" << endl;

    double p = pp;
    while (p <= pk + dp / 2.0) { // додаємо маленьку похибку dp/2 для точного охоплення pk
        y = z(p * p + 1) - z(p * p - 1) + 2 * z(p);

        cout << "|" << setw(10) << setprecision(2) << p << " |"
            << setw(12) << setprecision(5) << y << " |" << endl;

        p += dp;
    }
    cout << "---------------------------" << endl;

    return 0;
}