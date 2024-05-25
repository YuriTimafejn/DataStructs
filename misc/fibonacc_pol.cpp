#include<iostream>

long fibonacci(long n) {
    if (n == 0) return 0;
    long values[n];
    values[0] = 0;
    values[1] = 1;
    for(int i=2;i<=n;i++){
        values[i] = values[i-1] + values[i-2];
    }    
    return values[n];
}

int main() {
    long n {};
    std::cin >> n;
    std::cout << std::endl;
    long result = fibonacci(n);

    std::cout << "Result:\t" << result << std::endl;

    return 0;
}
