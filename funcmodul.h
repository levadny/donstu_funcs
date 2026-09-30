#pragma once

#include <cmath>
#include "functemplate.h"

class FuncModul : public FuncTemplate<double> {
public:

  // ctor
  FuncModul() = delete;

  // ctor with params
  FuncModul(std::vector<double> koefs) : FuncTemplate<double>(koefs) {
    ;
  }

  // calculate function
  double calc(double const &x) const override {
    double a = (this->m_koefs && !this->m_koefs->empty())
        ? (*this->m_koefs)[0]
        : 1.0;

    return std::abs(a * x);
  }
};
