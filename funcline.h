#pragma once

#include "functemplate.h"

class FuncLine : public FuncTemplate<double> {
public:
  // ctor without params
  FuncLine() = delete;
  // ctor with params
  FuncLine(std::vector<double> koefs) : FuncTemplate<double>(koefs) {
    this->setTitle("Line");
  }
  // ctor copy
  FuncLine(FuncLine const &other) : FuncTemplate<double>(std::ref(other)) {
    ;
  }
  // ctor move
  FuncLine(FuncLine &&other) : FuncTemplate<double>(std::move(other)) {
    ;
  }
  // assignment copy
  FuncLine& operator=(FuncLine const &other) {
    FuncTemplate<double>::operator=(other);
    return *this;
  }
  // assignment move
  FuncLine& operator=(FuncLine &&other) {
    FuncTemplate<double>::operator=(std::move(other));
    return *this;
  }
  // dtor
  virtual ~FuncLine() {
    ;
  }
  // calculate function
  double calc(double const &x) const override {
    return this->m_koefs->at(0) * x + this->m_koefs->at(1);
  }
  // input koefs
  void input(std::vector<double> const &koefs) {
    FuncTemplate<double>::input(koefs);
  }
};
