#include <iostream>
#include <cmath>  // mathematical manipulation
#include <string> // string manipulation 
#include <algorithm> // functionality like sorting searching 
#include <vector> // to hold our test cases 
#include <utility> // for pair

long long extractDigits(long long num, int n, bool flag) {
    long long divisor = pow(10, n / 2);
    return (flag == 0) ? num / divisor : num % divisor;
}

long long divideNmultiply(long long A, long long B, int n) {
    if (n == 1) {
        return A * B;
    }

    if (n % 2 != 0) {
        n++;
    }

    long long a = extractDigits(A, n, 0);
    long long b = extractDigits(A, n, 1);
    long long c = extractDigits(B, n, 0);
    long long d = extractDigits(B, n, 1);

    long long lh = divideNmultiply(a, c, n / 2);
    long long rh = divideNmultiply(b, d, n / 2);
    long long middle = divideNmultiply(a + b, c + d, n / 2) - lh - rh;

    return lh * pow(10, n) + middle * pow(10, n / 2) + rh;
}

long long startMultiplication(long long A, long long B) {
    int sizeA = std::to_string(A).length();
    int sizeB = std::to_string(B).length();
    int n = std::max(sizeA, sizeB);

    if (n % 2 != 0) {
        n++;
    }

    bool negativeResult = (A < 0) ^ (B < 0);
    long long result = divideNmultiply(abs(A), abs(B), n);

    return negativeResult ? -result : result;
}

int main() {
    std::vector<std::pair<long long, long long>> testCases = {
        {1, 9},
        {1234567890, 1286608618},
        {12345678, 87},
        {100872863, 292842910},
        {-1234, 53212678},
        {123321234, -5678},
        {-12345678, -90876541},
        {0, 5231231678},
        {1232131134, 0},
        {0, 0}
    };

    for (const auto& testCase : testCases) {
        long long A = testCase.first;
        long long B = testCase.second;
        long long result = startMultiplication(A, B);
        std::cout << "Result of multiplication A = " << A << " and B = " << B << " : " << result << std::endl;
    }

    return 0;
}
