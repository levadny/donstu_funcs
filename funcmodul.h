#pragma once

#include <cmath>
#include "functemplate.h"

template<class T>
class FuncModul : public FuncTemplate<T> {
public:

  // ctor
  FuncModul() : FuncTemplate<T>() {
    ;
  }

  // ctor with params
  explicit FuncModul(std::vector<T> const &koefs)
      : FuncTemplate<T>(koefs) {
    ;
  }

  // calculate function
  T calc(T const &x) const override {
    T a = (this->m_koefs && !this->m_koefs->empty())
        ? (*this->m_koefs)[0]
        : T(1);

    return std::abs(a * x);
  }
};
