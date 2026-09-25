#pragma once
#include "functemplate.h"

class FuncCub : public FuncTemplate<double>{
public:
//конструктор с параметрами
FuncCub(std::vector<double> koefs):FuncTempalte<double>(koefs){
}
//вычисление функции
double calc(double const&x) const override{
return this->m_koefs-.at(0)*x*x*x;
}
};

