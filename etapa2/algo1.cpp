#include "algo1.h"

std::vector<int> filter_non_prime_fermat(const std::vector<int>& sequence) {
    std::vector<int> primes;
    std::vector<int>::const_iterator number;

    for (number = sequence.begin(); number != sequence.end(); number++) {
        if (is_prime(*number, 50)) {
            primes.push_back(*number);
        }
    }

    return primes;
}

static unsigned long long power(unsigned long long a, unsigned int n, const unsigned int p) {
    unsigned long long ans = 1;

    while (n > 0) {
        if (n & 1) {
            ans = (ans * a) % p;
        }
        n >>= 1;
        a = (a * a) % p;
    }

    return ans;
}

static bool fermat_test(const unsigned int n) {
    unsigned long long a = 2 + rand() % (n - 4);
    if (power(a, n - 1, n) != 1) {
        return false;
    }
    return true;
}

static bool is_prime(const unsigned int n, unsigned int k) {
    if (n <= 1 || n == 4) {
        return false;
    }
    if (n <= 3) {
        return true;
    }

    while (k > 0) {
        if (!fermat_test(n)) {
            return false;
        }
        k--;
    }
    return true;
}
