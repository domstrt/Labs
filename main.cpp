#include <iostream>
using namespace std;

class Fraction {
private:
    int whole; // целая часть
    unsigned int fraction; // дробная часть
public:
    Fraction(int w, unsigned int f) {
        whole = w;
        fraction = f;
    }
    Fraction operator+(const Fraction& other) const {
        int w = whole + other.whole;
        unsigned int f = fraction + other.fraction;
        if (f >= 1000000) {
            w++;
            f -= 1000000;
        }
        return Fraction(w, f);
    }
    Fraction operator-(const Fraction& other) const {
        int w = whole - other.whole;
        unsigned int f = fraction - other.fraction;
        if (f >= 1000000) {
            w--;
            f += 1000000;
        }
        return Fraction(w, f);
    }
    Fraction operator*(const Fraction& other) const {
        int w = whole * other.whole;
        unsigned int f = fraction * other.fraction;
        if (f >= 1000000) {
            w += f / 1000000;
            f %= 1000000;
        }
        return Fraction(w, f);
    }
    bool operator==(const Fraction& other) const {
        return (whole == other.whole && fraction == other.fraction);
    }
    void print() const {
        cout << whole << "," << fraction << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Fraction f1(1, 500000);
    Fraction f2(2, 750000);
    Fraction f3 = f1 + f2;
    Fraction f4 = f2 - f1;
    Fraction f5 = f1 * f2;
    bool equal = (f1 == f2);
    f1.print();
    f2.print();
    f3.print();
    f4.print();
    f5.print();
    cout << (equal ? "равны" : "не равны") << endl;
    return 0;
}
