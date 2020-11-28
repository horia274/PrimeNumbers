import random
import os

def sieve_of_eratosthenes(n):
    bool_primes = [True for i in range(n + 1)]
    bool_primes[0], bool_primes[1] = False, False
    for p in range(2, n + 1):
        if bool_primes[p]:
            for i in range(p * p, n + 1, p):
                bool_primes[i] = False
    return bool_primes

def prime_composite(n):
    bool_primes = sieve_of_eratosthenes(n)
    prime = [i for i in range(n + 1) if bool_primes[i]]
    composite = [i for i in range(n + 1) if not bool_primes[i]]
    return [prime, composite]

def carmichael():
    return [561, 1105, 1729, 2465, 2821, 6601, 8911, 10585, 15841, 
    29341, 41041, 46657, 52633, 62745, 63973, 75361, 101101, 115921,
    126217, 162401, 172081, 188461, 252601, 278545, 294409, 314821, 
    334153, 340561, 399001, 410041, 449065, 488881, 552721, 656601,
    658801, 670033, 748657, 825265, 838201, 852841, 997633]

def random_choose(lower_bound, no_primes, no_composites, no_carmichales, prime, composite, carmichael):
    big_prime = [x for x in prime if x >= lower_bound]
    big_composite = [x for x in composite if x >= lower_bound]

    return [random.sample(big_prime, min(no_primes, len(big_prime))),
            random.sample(big_composite, min(no_composites, len(big_composite))),
            random.sample(carmichael, min(no_carmichales, len(carmichael)))]

def make_single_test(no_test, lower_bound, upper_bound, no_primes, no_composites, no_carmichales):
    [primes, composites] = prime_composite(upper_bound)
    carmichaels = carmichael()
    [random_primes, random_composites, random_carmichaels] = random_choose(lower_bound, no_primes, no_composites, no_carmichales,
                                                                            primes, composites, carmichaels)
    
    for charmicael in carmichaels:
        if charmicael in random_composites:
            random_composites.remove(charmicael)

    nums = random_primes + random_composites + random_carmichaels
    nums = random.sample(nums, len(nums))

    dir_name = os.path.dirname(__file__)

    path_in = dir_name + '/in/test' + str(no_test) + '.in'
    path_ref = dir_name + '/ref/test' + str(no_test) + '.ref'

    fin = open(path_in, 'w')
    fref = open(path_ref, 'w')

    fin.write(str(len(nums)) + '\n')
    fref.write(str(len(random_primes)) + '\n')

    for num in nums:
        fin.write(str(num) + ' ')
        if num in random_primes:
            fref.write(str(num) + ' ')

    fin.close()
    fref.close()

def make_all_tests():
    make_single_test(0, 0, 10, 4, 6, 0)
    make_single_test(1, 0, 100, 20, 70, 1)
    make_single_test(2, 0, 1000, 150, 700, 2)
    make_single_test(3, 1000000, 1500000, 500, 1000, 4)
    make_single_test(4, 5000000, 10000000, 2000, 5000, 5)
    make_single_test(5, 10000000, 50000000, 15000, 35000, 12)
    make_single_test(6, 0, 100000, 9500, 90000, 16)
    make_single_test(7, 0, 500000, 41000, 900000, 24)
    make_single_test(8, 100000, 10000000, 78000, 900000, 31)
    make_single_test(9, 1000, 100000000, 2000000, 4000000, 40)

make_all_tests()
