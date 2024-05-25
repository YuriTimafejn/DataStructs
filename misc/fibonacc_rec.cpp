#include<iostream>


long fibonacci(long n) {
    if (n == 0) 
    {
        // std::cout << "ret0" << std::endl;
        return 0;
    }
    else if (n == 1) 
    {
        // std::cout << "ret1" << std::endl;
        return 1;
    } else {
        // std::cout << "ret:[" << (n-1) << "," << (n-2) << "]"<< std::endl;
        return fibonacci((n - 1)) + fibonacci((n - 2));
    }
}

int main() {
    long n = 11;
    long result = fibonacci(n);

    std::cout << "Result:\t" << result << std::endl;

    return 0;
}
