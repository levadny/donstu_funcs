#include <iostream>
#include <vector>
#include <iomanip>
#include "funcline.h"
#include "funcfastosc.h"
#include "funcmodul.h"

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

    std::cout << "\n--- Testing FuncModul ---" << std::endl;

    // По условию: a = 1
    // Формула: y = abs(a * x)
    std::vector<double> k_modul = {1.0};
    FuncModul modul(k_modul);

    std::cout << "Manual mode (FuncModul)" << std::endl;

    // Проверим значения для V-образного графика
    for(double x = -3.0; x <= 3.0; x += 0.5){
        std::cout << "y(" << std::setw(4) << x << ") = " << modul.calc(x) << std::endl;
    }

    std::cout << "All array mode (FuncModul)" << std::endl;

    // Шаг 0.5
    auto res_modul = modul.calcAll(-3.0, 0.5, 3.0);

    for(size_t i = 0; i < res_modul.size(); ++i){
        std::cout << "y(" << std::setw(4) << res_modul[i].first << ") = " << res_modul[i].second << std::endl;
    }


  return 0;
}
