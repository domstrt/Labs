#include <iostream>
#include <string>

using namespace std;

struct Pair {
    int first;
    unsigned int second;

    Pair(int f = 0, unsigned int s = 0) : first(f), second(s) {}
};

class Fraction {
private:
    int whole;
    unsigned int fraction;

public:
    Fraction(int w = 0, unsigned int f = 0) : whole(w), fraction(f) {}

    friend Fraction operator+(const Fraction& f1, const Fraction& f2);
    friend Fraction operator-(const Fraction& f1, const Fraction& f2);
    friend Fraction operator*(const Fraction& f1, const Fraction& f2);
    friend bool operator==(const Fraction& f1, const Fraction& f2);
    friend ostream& operator<<(ostream& os, const Fraction& f);

    string toString() const {
        string result = to_string(whole);
        result += ".";
        result += to_string(fraction);
        return result;
    }
};

Fraction operator+(const Fraction& f1, const Fraction& f2) {
    int newWhole = f1.whole + f2.whole;
    unsigned int newFraction = f1.fraction + f2.fraction;
    if (newFraction >= 1000000) {
        newWhole += 1;
        newFraction -= 1000000;
    }
    return Fraction(newWhole, newFraction);
}

Fraction operator-(const Fraction& f1, const Fraction& f2) {
    int newWhole = f1.whole - f2.whole;
    unsigned int newFraction = f1.fraction - f2.fraction;
    if (newFraction < 0) {
        newWhole -= 1;
        newFraction += 1000000;
    }
    return Fraction(newWhole, newFraction);
}

Fraction operator*(const Fraction& f1, const Fraction& f2) {
    int newWhole = f1.whole * f2.whole;
    unsigned int newFraction = f1.fraction * f2.fraction;
    if (newFraction >= 1000000) {
        newWhole += 1;
        newFraction -= 1000000;
    }
    return Fraction(newWhole, newFraction);
}

bool operator==(const Fraction& f1, const Fraction& f2) {
    return (f1.whole == f2.whole && f1.fraction == f2.fraction);
}

ostream& operator<<(ostream& os, const Fraction& f) {
    os << "Целая часть: " << f.whole << ", Дробная часть: " << f.fraction << endl;
    return os;
}

int main() {
    setlocale(LC_ALL, "Russian");

    Pair p(5, 10);
    cout << "Pair: " << p.first << ", " << p.second << endl;

    Fraction f1(3, 500000);
    Fraction f2(2, 750000);
    Fraction f3 = f1 + f2;
    Fraction f4 = f1 - f2;
    Fraction f5 = f1 * f2;

    cout << "f1: " << f1 << "f2: " << f2 << "f1 + f2: " << f3 << "f1 - f2: " << f4 << "f1 * f2: " << f5 << endl;

    if (f1 == f2) {
        cout << "f1 и f2 равны" << endl;
    }
    else {
        cout << "f1 и f2 не равны" << endl;
    }

    cout << "f1 в строковом виде: " << f1.toString() << endl;

    return 0;
}
