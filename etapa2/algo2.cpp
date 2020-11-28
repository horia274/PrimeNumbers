#include "algo2.h"

std::vector<int> filter_non_prime_miller_rabin(const std::vector<int>& sequence) {
    std::vector<int> primes;
    std::vector<int>::const_iterator number;

    for (number = sequence.begin(); number != sequence.end(); number++) {
        if (is_prime(*number, 6)) {
            primes.push_back(*number);
        }
    }

    return primes;
}

static unsigned long power(unsigned long a, unsigned int n, const unsigned int p) {
    unsigned long ans = 1;

    while (n > 0) {
        if (n & 1) {
            ans = (ans * a) % p;
        }
        n >>= 1;
        a = (a * a) % p;
    }

    return ans;
}

static bool miller_rabin_test(const unsigned int n) {
    unsigned long long a = 2 + rand() % (n - 4);
    unsigned int d = n - 1;
    while (!(d & 1)) {
        d >>= 1;
    }
    unsigned long x = power(a, d, n);
    
    if (x == 1 || x == n - 1) {
        return true;
    }

    while (d != n - 1) {
        x = (x * x) % n;
        d <<= 1;
        if (x == 1) {
            return false;
        }
        if (x == n - 1) {
            return true;
        }
    }

    return false;
}

static bool is_prime(const unsigned int n, unsigned int k) {
    if (n <= 1 || n == 4) {
        return false;
    }
    if (n <= 3) {
        return true;
    }

    while (k > 0) {
        if (!miller_rabin_test(n)) {
            return false;
        }
        k--;
    }
    return true;
}
