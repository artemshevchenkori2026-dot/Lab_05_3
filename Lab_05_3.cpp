// -2 2 10
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cassert>

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

// Unit-тест для перевірки функції z(x)
void testZ() {
    // Тест для |x| >= 1 (наприклад, x = 1.0)
    double expected1 = (sin(1.0) + 1.0) / (pow(cos(1.0), 2) + exp(1.0));
    assert(abs(z(1.0) - expected1) < 1e-5);

    // Тест для |x| < 1 (наприклад, x = 0.0)
    // При x = 0: S = 1, e^0 = 1, тобто z(0) = 1
    assert(abs(z(0.0) - 1.0) < 1e-5);
}

int main() {
    // Запуск unit-тесту
    testZ();

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
    while (p <= pk) {
        y = z(p * p + 1) - z(p * p - 1) + 2 * z(p);

        cout << "|" << setw(10) << setprecision(2) << p << " |"
            << setw(12) << setprecision(5) << y << " |" << endl;

        p += dp;
    }
    cout << "---------------------------" << endl;

    return 0;
}