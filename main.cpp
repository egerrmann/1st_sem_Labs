//variant 11
#include <iostream>
#include <cmath>
#include <iomanip>

/*
double fact(int z) //вычисление факториала числа
{
    if (z < 0)
        return 0;
    if (z == 0)
        return 1;
    else
        return z * fact(z-1);
}
*/

int main() {
    int k, n = 1, l;
    double a, epsilon, s = 0, f;
    int x;
    std::cout << "Enter number of signs after comma:" << std::endl;
    std::cin >> l;
    std::cout << std::fixed << std::setprecision(l); //количество знаков после запятой
    std::cout << "insert integer k > 1:" << std::endl;
    std::cin >> k;
    std::cout << "insert any x:" << std::endl;
    std::cin >> x;
    a = (exp(x) - exp(-x)) / 2; //значение функции
    epsilon = 1 / (pow(10, k)); //вычисление эпсилон
    std::cout << "a = " << a << std::endl;
    f = x;
    while (n > 0) {
        f = f * x * x / (n + 1) / (n + 2); //новое слагаемое в общей сумме
        s += f; // сумма чисел в ряду Тейлора
        n += 2;
        if ((f < epsilon) && (f > 0))
            break;
    }
    std::cout << "epsilon = " << epsilon << std::endl << "last term = " << f << std::endl << "general sum = " << s << std::endl;

return 0;
}