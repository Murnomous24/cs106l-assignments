#include<utility>
#include<iostream>
#include<cmath>
using Zeros = std::pair<double, double>;
using Solution = std::pair<bool, Zeros>;
Solution solveQuadratic(int a, int b, int c) {
    double delta = b*b - 4 * a * c;
    double x1, x2;
    x1 = x2 = 0;

    if(delta >= 0) {
        x1 = (double(-b) - sqrt(delta)) / (2 * double(a));
        x2 = (double(-b) + sqrt(delta)) / (2 * double(a));   
    }
    bool has_a_soultion = delta >= 0;
    
    return std::pair{has_a_soultion, std::pair{x1, x2}};
}

int main() {
    int a, b, c;
    std::cout << "input three numbers(ax^2 + bx + c = 0): ";
    std::cin >> a >> b >> c;

    Solution res = solveQuadratic(a, b, c);
    std::string res2 = res.first == 1 ? "true" : "false";
    std::cout << "Have a soultion: " << res2 << std::endl;
    if(res.first) {
        std::cout << "x1: " << res.second.first << " x2: " << res.second.second << std::endl;
    }
    return 0;
}