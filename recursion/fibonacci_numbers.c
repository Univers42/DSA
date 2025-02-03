#include <stdio.h>

void multiply_matrices(int F[2][2], int M[2][2]) {
    int x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    int y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    int z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    int w = F[1][0] * M[0][1] + F[1][1] * M[1][1];
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

void power(int F[2][2], int n) {
    if (n == 0 || n == 1)
        return;
    int M[2][2] = {{1, 1}, {1, 0}};
    power(F, n / 2);
    multiply_matrices(F, F);
    if (n % 2 != 0)
        multiply_matrices(F, M);
}

int fibonacci_optimized(int n) {
    if (n == 0) return 0;
    int F[2][2] = {{1, 1}, {1, 0}};
    power(F, n - 1);
    return F[0][0];
}

int main() {
    int n = 10;
    printf("Fibonacci(%d) = %d\n", n, fibonacci_optimized(n));
    return 0;
}
