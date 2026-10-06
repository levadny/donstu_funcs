#pragma once

#include <vector>

template<class T>
class FuncTemplate {
protected:

  // koefs
  std::vector<T> *m_koefs;

public:

  // ctor
  FuncTemplate() : m_koefs(new std::vector<T>()) {
    ;
  }

  // ctor with params
  explicit FuncTemplate(std::vector<T> const &koefs) : m_koefs(new std::vector<T>(koefs)) {
    ;
  }

  // ctor copy
  FuncTemplate(FuncTemplate const &other) {
    this->m_koefs = (other.m_koefs) ? new std::vector<T>(*other.m_koefs) : nullptr;
  }

  // ctor move
  FuncTemplate(FuncTemplate &&other) noexcept {
    this->m_koefs = other.m_koefs;
    other.m_koefs = nullptr;
  }

  // assignment copy
  FuncTemplate& operator=(FuncTemplate const &other) {
    if (this != &other) {
      delete this->m_koefs;
      this->m_koefs = (other.m_koefs) ? new std::vector<T>(*other.m_koefs) : nullptr;
    }
    return *this;
  }

  // assignment move
  FuncTemplate& operator=(FuncTemplate &&other) noexcept {
    if (this != &other) {
      delete this->m_koefs;
      this->m_koefs = other.m_koefs;
      other.m_koefs = nullptr;
    }
    return *this;
  }

  // dtor
  virtual ~FuncTemplate() {
    delete this->m_koefs;
  }

  // input koefs
  void input(std::vector<double> const &koefs) {
    if (this->m_koefs){
      delete this->m_koefs;
    }
    this->m_koefs = new std::vector<T>(koefs);
  }

  // calculate function
  virtual T calc(T const &x) const {
    return T();
  }

  // calculate values of function in some range
  std::vector<std::pair<T, T>> calcAll(T const &xMin, T const &xStep, T const &xMax) const {
    std::vector<std::pair<T, T>> res;
    T x = xMin;
    while(x < xMax){
      res.push_back(std::make_pair(x, this->calc(x)));
      x += xStep;
    }
    return res;
  }
};
