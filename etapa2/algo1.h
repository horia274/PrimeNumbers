#ifndef ALGO1_H
#define ALGO1_H

#include <vector>
#include <random>

/**
 * For a given sequence of integer numbers, filter the non-prime set of numbers.
 *
 * @sequence: The original sequence of numbers.
 * @returns: The vector with only the prime numbers from the original sequence. (in the same relative order)
 */
std::vector<int> filter_non_prime_fermat(const std::vector<int>& sequence);

/**
 * Compute a^n (mod p) 
 * 
 * @param a The basis of power
 * @param n The exponent of power
 * @param p The divisor which will give the rest
 * @return The rest on division
 */
static unsigned long long power(unsigned long long a, unsigned int n, const unsigned int p);

/**
 * Apply just once the Fermat algorithm
 * 
 * @param n Test the primality of n
 * @return true, if n may be prime
 * @return false, if n is definitely composite
 */
static bool fermat_test(const unsigned int n);

/**
 * Repeat Fermat algorithm many times
 * 
 * @param n Test the primality of n
 * @param k How many times, the algorithm repeats
 * @return true, if fermat_test is true k times
 * @return false, if fermat_test is false once
 */
static bool is_prime(const unsigned int n, unsigned int k);

#endif
