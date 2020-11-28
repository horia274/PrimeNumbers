#ifndef ALGO2_H
#define ALGO2_H

#include <vector>
#include <random>
#include <iostream>

/**
 * For a given sequence of integer numbers, filter the non-prime set of numbers.
 *
 * @sequence: The original sequence of numbers.
 * @returns: The vector with only the prime numbers from the original sequence. (in the same relative order)
 */
std::vector<int> filter_non_prime_miller_rabin(const std::vector<int>& sequence);

static unsigned long power(unsigned long a, unsigned int n, const unsigned int p);

static bool miller_rabin_test(const unsigned int n);

static bool is_prime(const unsigned int n, unsigned int k);

#endif
