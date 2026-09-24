#pragma once

#include "functemplate.h"
#include <stdexcept>

// y = a / (b * x)
class FuncHyperbola : public FuncTemplate<double> {
public:
  // ctor without params
  FuncHyperbola() = delete;

  // ctor with params
  // koefs[0] = a, koefs[1] = b
  FuncHyperbola(std::vector<double> koefs) : FuncTemplate<double>(koefs) {
    ;
  }

  // ctor copy
  FuncHyperbola(FuncHyperbola const &other) : FuncTemplate<double>(std::ref(other)) {
    ;
  }

  // ctor move
  FuncHyperbola(FuncHyperbola &&other) : FuncTemplate<double>(std::move(other)) {
    ;
  }

  // assignment copy
  FuncHyperbola& operator=(FuncHyperbola const &other) {
    FuncTemplate<double>::operator=(other);
    return *this;
  }

  // assignment move
  FuncHyperbola& operator=(FuncHyperbola &&other) {
    FuncTemplate<double>::operator=(std::move(other));
    return *this;
  }

  // dtor
  virtual ~FuncHyperbola() {
    ;
  }

  // calculate function: y = a / (b * x)
  double calc(double const &x) const override {
    const double a = this->m_koefs->at(0);
    const double b = this->m_koefs->at(1);

    // защита от деления на ноль
    if (b == 0.0 || x == 0.0) {
      return 0.0;
    }

    return a / (b * x);
  }

  // input koefs
  void input(std::vector<double> const &koefs) {
    FuncTemplate<double>::input(koefs);
  }
};