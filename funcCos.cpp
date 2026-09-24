#pragma once
#include <cmath>
#include "functemplate.h"

class FuncCos : public FuncTemplate<double> {
public:
  // ctor without params
  FuncCos() = delete;
  // ctor with params
  FuncCos(std::vector<double> koefs) : FuncTemplate<double>(koefs) {
    ;
  }
  // ctor copy
  FuncCos(FuncCos const &other) : FuncTemplate<double>(std::ref(other)) {
    ;
  }
  // ctor move
  FuncCos(FuncCos &&other) : FuncTemplate<double>(std::move(other)) {
    ;
  }
  // assignment copy
  FuncCos& operator=(FuncCos const &other) {
    FuncTemplate<double>::operator=(other);
  }
  // assignment move
  FuncCos& operator=(FuncCos &&other) {
    FuncTemplate<double>::operator=(std::move(other));
  }
  // dtor
  virtual ~FuncCos() {
    ;
  }
  // calculate function
  double calc(double const &x) const override {
    return this->m_koefs->at(0) * std::cos(this->m_koefs->at(1) * x);
  }
  // input koefs
  void input(std::vector<double> const &koefs) {
    FuncTemplate<double>::input(koefs);
  }
};