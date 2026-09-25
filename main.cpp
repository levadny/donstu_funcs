#include <iostream>
#include <vector>
#include <iomanip>
#include "funcline.h"
#include "funcfastosc.h"
#include "funcarctan.h"
#include <cassert>
#include <cmath>

int main() {
  std::cout << "Func test example" << std::endl;
  std::vector k = {1.1, -3.5};
  FuncLine line(k);
  // each point in manual mode
  std::cout << "Manual mode" << std::endl;
  for(int i = -10; i < 10; ++i){
    std::cout << "y(" << std::setw(3) << i << ") = " << line.calc(i) << std::endl;
  }
  // each point for array of x
  std::cout << "All array mode" << std::endl;
  auto res = line.calcAll(-10, 0.1, 10);
  for(size_t i = 0; i < res.size(); ++i){
    std::cout << "y(" << std::setw(4) << res[i].first << ") = " << res[i].second << std::endl;
  }
      std::cout << "\n--- Testing FuncFastOsc ---" << std::endl;
    // По условию: a = 1, b = 1
    std::vector<double> k_osc = {1.0, 1.0}; 
    FuncFastOsc fastOsc(k_osc);

    std::cout << "Manual mode (FuncFastOsc)" << std::endl;
    // Проверим значения вблизи нуля и в нуле
    double test_vals[] = {-1.0, -0.5, -0.1, 0.0, 0.1, 0.5, 1.0};
    for(double x : test_vals){
        std::cout << "y(" << std::setw(4) << x << ") = " << fastOsc.calc(x) << std::endl;
    }

    std::cout << "All array mode (FuncFastOsc)" << std::endl;
    // Шаг 0.2, чтобы увидеть колебания. Обратите внимание: около нуля они очень частые.
    auto res_osc = fastOsc.calcAll(-2.0, 0.2, 2.0);
    for(size_t i = 0; i < res_osc.size(); ++i){
        std::cout << "y(" << std::setw(4) << res_osc[i].first << ") = " << res_osc[i].second << std::endl;
    }


    // Тестирование функции арктангенса
    std::cout << "\n--- Testing FuncArctan ---" << std::endl;

    // Создаём объект с коэффициентами a = 1, b = 1
    FuncArctan arctanFunc;

    // Точность сравнения вещественных чисел
    const double eps = 1e-10;
    const double pi = std::acos(-1.0);

    // Тест 1: arctan(0) = 0
    assert(std::abs(arctanFunc.calc(0.0)) < eps);

    // Тест 2: arctan(1) = pi / 4
    assert(std::abs(arctanFunc.calc(1.0) - pi / 4.0) < eps);

    // Тест 3: arctan(-1) = -pi / 4
    assert(std::abs(arctanFunc.calc(-1.0) + pi / 4.0) < eps);

    // Тест 4: вычисление нескольких значений
    auto results = arctanFunc.calcAll(-1.0, 1.0, 2.0);

    assert(results.size() == 3);

    for (const auto& point : results) {
        assert(
            std::abs(
                point.second - std::atan(point.first)
            ) < eps
        );
    }

    std::cout << "FuncArctan tests passed!" << std::endl;
  return 0;
}
