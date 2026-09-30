#pragma once

#include "functemplate.h"
#include <cmath>
#include <limits>

// Класс для функции y = a * sin(b / x)
// "Быстрые колебания около нуля"
class FuncFastOsc : public FuncTemplate<double> {
public:
    // ctor without params
    FuncFastOsc() = delete;

    // ctor with params
    explicit FuncFastOsc(std::vector<double> koefs) : FuncTemplate<double>(koefs) {
        ;
    }

    // ctor copy
    FuncFastOsc(FuncFastOsc const &other) : FuncTemplate<double>(std::ref(other)) {
        ;
    }

    // ctor move
    FuncFastOsc(FuncFastOsc &&other) : FuncTemplate<double>(std::move(other)) {
        ;
    }

    // assignment copy
    FuncFastOsc& operator=(FuncFastOsc const &other) {
        FuncTemplate<double>::operator=(other);
        return *this; // Обязательно возвращаем *this для цепочек присваивания
    }

    // assignment move
    FuncFastOsc& operator=(FuncFastOsc &&other) {
        FuncTemplate<double>::operator=(std::move(other));
        return *this; // Обязательно возвращаем *this
    }

    // dtor
    virtual ~FuncFastOsc() {
        ;
    }

    // calculate function: y = a * sin(b / x)
    double calc(double const &x) const override {
        // Обработка разрыва в нуле (деление на ноль)
        // Используем epsilon для сравнения с нулем, так как double
        if (std::abs(x) < 1e-12) {
            return std::numeric_limits<double>::quiet_NaN(); // Возвращаем NaN (Not a Number)
        }
        
        // a = m_koefs[0], b = m_koefs[1]
        double a = this->m_koefs->at(0);
        double b = this->m_koefs->at(1);
        
        return a * std::sin(b / x);
    }

    // input koefs
    void input(std::vector<double> const &koefs) {
        FuncTemplate<double>::input(koefs);
    }
};