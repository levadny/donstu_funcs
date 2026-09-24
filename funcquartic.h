#pragma once

#include "functemplate.h"

// Класс для функции y = a * x^4 - b * x^2 + c
class FuncQuartic : public FuncTemplate<double> {
public:
    // ctor without params
    FuncQuartic() = delete;

    // ctor with params
    explicit FuncQuartic(std::vector<double> koefs) : FuncTemplate<double>(koefs) {
        ;
    }

    // ctor copy
    FuncQuartic(FuncQuartic const &other) : FuncTemplate<double>(std::ref(other)) {
        ;
    }

    // ctor move
    FuncQuartic(FuncQuartic &&other) : FuncTemplate<double>(std::move(other)) {
        ;
    }

    // assignment copy
    FuncQuartic& operator=(FuncQuartic const &other) {
        FuncTemplate<double>::operator=(other);
        return *this;
    }

    // assignment move
    FuncQuartic& operator=(FuncQuartic &&other) {
        FuncTemplate<double>::operator=(std::move(other));
        return *this;
    }

    // dtor
    virtual ~FuncQuartic() {
        ;
    }

    // calculate function: y = a * x^4 - b * x^2 + c
    double calc(double const &x) const override {
        // a = m_koefs[0], b = m_koefs[1], c = m_koefs[2]
        double a = this->m_koefs->at(0);
        double b = this->m_koefs->at(1);
        double c = this->m_koefs->at(2);

        double x2 = x * x;
        return a * x2 * x2 - b * x2 + c;
    }

    // input koefs
    void input(std::vector<double> const &koefs) {
        FuncTemplate<double>::input(koefs);
    }
};