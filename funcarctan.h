
#pragma once

#include "functemplate.h"
#include <cmath>
#include <stdexcept>

// Функция арктангенса:
// y = a * arctan(b * x)

class FuncArctan : public FuncTemplate<double> {
public:

    // Конструктор с коэффициентами a = 1, b = 1
    explicit FuncArctan(
        const std::vector<double>& koefs = {1.0, 1.0}
    ) : FuncTemplate<double>(koefs) {

        if (koefs.size() != 2) {
            throw std::invalid_argument(
                "FuncArctan requires 2 coefficients"
            );
        }
    }

    // Вычисление значения функции
    double calc(const double& x) const override {

        double a = this->m_koefs->at(0);
        double b = this->m_koefs->at(1);

        return a * std::atan(b * x);
    }
};