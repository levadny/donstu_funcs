#pragma once
#include <cmath>

// Класс для функции: y = a * x^2 * sin(b / x)
class FuncDamped {
private:
    double a;
    double b;

public:

    FuncDamped(double a_val = 1.0, double b_val = 1.0) : a(a_val), b(b_val) {}

    // Метод вычисления значения функции
    double calculate(double x) const {
        if (x == 0.0) {
            // В точке 0 функция не определена (разрыв), 
            // но предел равен 0. Можно вернуть 0 или NaN.
            return 0.0; 
        }
        return a * x * x * std::sin(b / x);
    }
};
