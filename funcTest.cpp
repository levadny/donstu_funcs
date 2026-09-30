#include <gtest/gtest.h>

#include "funcHyperbola.h"

// Обычное положительное значение
TEST(FuncHyperbolaTest, CalcPositiveValues)
{
    FuncHyperbola func({6.0, 3.0});

    // y = 6 / (3 * 2) = 1
    EXPECT_NEAR(func.calc(2.0), 1.0, 1e-9);
}

// Отрицательный x
TEST(FuncHyperbolaTest, CalcNegativeX)
{
    FuncHyperbola func({6.0, 3.0});

    // y = 6 / (3 * -2) = -1
    EXPECT_NEAR(func.calc(-2.0), -1.0, 1e-9);
}

// Отрицательный b
TEST(FuncHyperbolaTest, CalcNegativeB)
{
    FuncHyperbola func({6.0, -3.0});

    // y = 6 / (-3 * 2) = -1
    EXPECT_NEAR(func.calc(2.0), -1.0, 1e-9);
}

// Отрицательный a
TEST(FuncHyperbolaTest, CalcNegativeA)
{
    FuncHyperbola func({-6.0, 3.0});

    // y = -6 / (3 * 2) = -1
    EXPECT_NEAR(func.calc(2.0), -1.0, 1e-9);
}

// a = 0
TEST(FuncHyperbolaTest, ZeroA)
{
    FuncHyperbola func({0.0, 3.0});

    EXPECT_DOUBLE_EQ(func.calc(2.0), 0.0);
}

// b = 0
TEST(FuncHyperbolaTest, ZeroB)
{
    FuncHyperbola func({6.0, 0.0});

    // В твоём коде при b == 0 возвращается 0
    EXPECT_DOUBLE_EQ(func.calc(2.0), 0.0);
}

// x = 0
TEST(FuncHyperbolaTest, ZeroX)
{
    FuncHyperbola func({6.0, 3.0});

    // В твоём коде при x == 0 возвращается 0
    EXPECT_DOUBLE_EQ(func.calc(0.0), 0.0);
}

// Проверка другого набора коэффициентов
TEST(FuncHyperbolaTest, CalcDifferentValues)
{
    FuncHyperbola func({10.0, 5.0});

    // y = 10 / (5 * 2) = 1
    EXPECT_NEAR(func.calc(2.0), 1.0, 1e-9);
}

// Проверка дробного результата
TEST(FuncHyperbolaTest, CalcFraction)
{
    FuncHyperbola func({5.0, 2.0});

    // y = 5 / (2 * 2) = 1.25
    EXPECT_NEAR(func.calc(2.0), 1.25, 1e-9);
}