#pragma once

#include <cmath>
#include "functemplate.h"

class FuncStep : public FuncTemplate<double> {
public:
    // конструктор без параметров
    FuncStep() = delete;

    // конструктор с параметрами
    FuncStep(std::vector<double> koefs) : FuncTemplate<double>(koefs) {
        ;
    }

    // конструктор копирования
    FuncStep(FuncStep const& other) : FuncTemplate<double>(other) {
        ;
    }

    // конструктор перемещения
    FuncStep(FuncStep&& other) : FuncTemplate<double>(std::move(other)) {
        ;
    }

    // оператор присваивания копированием
    FuncStep& operator=(FuncStep const& other) {
        FuncTemplate<double>::operator=(other);
        return *this;
    }

    // оператор присваивания перемещением
    FuncStep& operator=(FuncStep&& other) {
        FuncTemplate<double>::operator=(std::move(other));
        return *this;
    }

    // деструктор
    virtual ~FuncStep() {
        ;
    }

    // вычисление функции: y = trunc(a * x)
    double calc(double const& x) const override {
        return std::trunc(this->m_koefs->at(0) * x);
    }

    // ввод коэффициентов
    void input(std::vector<double> const& koefs) {
        FuncTemplate<double>::input(koefs);
    }
};