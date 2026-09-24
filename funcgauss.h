#pragma once

#include "functemplate.h"

class FuncGauss : public FuncTemplate<double> {
public:
    // ctor without params
    FuncGauss() = delete;
    // ctor with params
    FuncGauss(std::vector<double> koefs) : FuncTemplate<double>(koefs) {
        ;
    }
    // ctor copy
    FuncGauss(FuncGauss const& other) : FuncTemplate<double>(std::ref(other)) {
        ;
    }
    // ctor move
    FuncGauss(FuncGauss&& other) : FuncTemplate<double>(std::move(other)) {
        ;
    }
    // assignment copy
    FuncGauss& operator=(FuncGauss const& other) {
        FuncTemplate<double>::operator=(other);
    }
    // assignment move
    FuncGauss& operator=(FuncGauss&& other) {
        FuncTemplate<double>::operator=(std::move(other));
    }
    // dtor
    virtual ~FuncGauss() {
        ;
    }
    // calculate function
    double calc(double const& x) const override {
        return this->m_koefs->at(0) * std::exp(this->m_koefs->at(1) * std::pow(x, 2)) ;
    }
    // input koefs
    void input(std::vector<double> const& koefs) {
        FuncTemplate<double>::input(koefs);
    }
};
