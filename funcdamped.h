#pragma once

#include <cmath>
#include <vector>
#include <limits>
#include "functemplate.h"


class FuncDamped : public FuncTemplate<double> {
public:
    explicit FuncDamped(std::vector<double> const &koefs = {1.0, 1.0})
        : FuncTemplate<double>(koefs) {}

    double calc(double const &x) const override {
        const double a = (*m_koefs)[0];
        const double b = (*m_koefs)[1];

        // Численно "почти ноль" — считаем предел равным 0
        constexpr double eps = std::numeric_limits<double>::epsilon() * 100.0;
        if (std::abs(x) < eps) {
            return 0.0;
        }
        return a * x * x * std::sin(b / x);
    }
};
