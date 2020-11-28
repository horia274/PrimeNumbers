#ifndef ALGO2_H
#define ALGO2_H

#include <vector>
#include <random>

/**
 * For a given sequence of integer numbers, filter the non-prime set of numbers.
 *
 * @sequence: The original sequence of numbers.
 * @returns: The vector with only the prime numbers from the original sequence. (in the same relative order)
 */
std::vector<int> filter_non_prime_miller_rabin(const std::vector<int>& sequence);

/**
 * Compute a^n (mod p) 
 * 
 * @param a The basis of power
 * @param n The exponent of power
 * @param p The divisor which will give the rest
 * @return The rest on division
 */
static unsigned long power(unsigned long a, unsigned int n, const unsigned int p);

/**
 * Apply just once the Miller-Rabin test
 * 
 * @param n Test the primality of n
 * @return true, if n may be prime
 * @return false, if n is definitely composite
 */
static bool miller_rabin_test(const unsigned int n);

/**
 * Repeat Miller-Rabin algorithm many times
 * 
 * @param n Test the primality of n
 * @param k How many times, the algorithm repeats
 * @return true, if miller_rabin_test is true k times
 * @return false, if miller_rabin_test is false once
 */
static bool is_prime(const unsigned int n, unsigned int k);

#endif
