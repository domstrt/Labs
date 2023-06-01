#include <iostream>
#include <locale.h> // библиотека для вывода русского языка
#include <cmath> // библиотека для математических функций

using namespace std;

class Trapezium_Prisma { // объявляем класс "Прямая призма"
private:
    double a, b, h, H; // объявляем поля класса
public:
    Trapezium_Prisma(double a, double b, double h, double H) { // конструктор класса
        this->a = a;
        this->b = b;
        this->h = h;
        this->H = H;
    }
    double base_area() { // метод для вычисления площади основания
        return (a + b) * h / 2;
    }
    double lateral_area() { // метод для вычисления боковой поверхности
        double l = sqrt(pow((b - a) / 2, 2) + pow(h, 2)); // вычисляем длину боковой стороны
        return (a + b + 2 * l) * H;
    }
    double total_area() { // метод для вычисления полной поверхности
        return 2 * base_area() + lateral_area();
    }
    double volume() { // метод для вычисления объема
        return base_area() * H;
    }
    double weight(double density) { // метод для вычисления веса
        return volume() * density;
    }
};

int main() {
    setlocale(LC_ALL, "Russian"); // устанавливаем русский язык для вывода в консоль
    double a, b, h, H, density; // объявляем переменные
    cout << "Введите длину меньшего основания трапеции: ";
    cin >> a;
    cout << "Введите длину большего основания трапеции: ";
    cin >> b;
    cout << "Введите высоту трапеции: ";
    cin >> h;
    cout << "Введите высоту призмы: ";
    cin >> H;
    cout << "Введите плотность материала: ";
    cin >> density;
    Trapezium_Prisma tp(a, b, h, H); // создаем объект класса
    cout << "Площадь основания: " << tp.base_area() << endl; // выводим результаты вычислений
    cout << "Боковая поверхность: " << tp.lateral_area() << endl;
    cout << "Полная поверхность: " << tp.total_area() << endl;
    cout << "Объем: " << tp.volume() << endl;
    cout << "Вес: " << tp.weight(density) << endl;
    return 0;
}
