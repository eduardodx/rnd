/*
 * Secure Random Number Generator
 *
 * This solution must exclusively read from the kernel's 
 * Cryptographically Secure Pseudorandom Number Generator (CSPRNG) 
 * and fail closed. 
 * Userspace Random Number Generators (RNGs) and insecure RNG 
 * fallbacks will not be accepted.
 *
 * Dependency:
 *
 *      Ubuntu:
 *          libsodium-dev
 *
 *      Other systems:
 *          Documentation at https://download.libsodium.org/libsodium/content/installation/
 *
 * Usage:
 *
 *      Step 1: make
 *      Step 2: ./rnd-sodium [number]
 *
 * Alternative method: 
 * 
 *      https://www.nist.gov/programs-projects/nist-randomness-beacon
 *
 * References:
 *
 *      - https://www.2uo.de/myths-about-urandom/
 *      - https://sockpuppet.org/blog/2014/02/25/safely-generate-random-numbers/
 *      - https://blog.cr.yp.to/20140205-entropy.html
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <sodium.h>

int main(int argc, char *argv[])
{
    /* 
     * Hang the program execution if no arguments are provided.
     */
    if (argc <= 1) {
        fprintf( stderr, "Usage: ./rnd-sodium [number]\n" );
        return -1;
    }

    
    /* 
     * Hang the program execution if libsodium cannot securely initiate.
     */
    if ( sodium_init() < 0 ) {
        fprintf( stderr, "Error initializing libsodium.\n" );
        return -1;
    }
    
    /* 
     * Define the variables.
     */
    char buf_string[4096];
    uint64_t random_number;
    uint64_t top = atoi( argv[1] );

    /*
     * buf_string will be an array of 4096 random bytes, not null-terminated 
     */
    randombytes_buf(buf_string, 4096);
    
    
    /* 
     * The randombytes_uniform() function returns an unpredictable value 
     * between 0 and upper_bound (excluded). 
     * Unlike randombytes_random() % upper_bound, it guarantees a uniform 
     * distribution of the possible output values even when upper_bound 
     * is not a power of 2. Note that an upper_bound < 2 leaves only a single 
     * element to be chosen, namely 0.
     */
    random_number = randombytes_uniform(top);


    /* 
     * Add 1 to random_number to make top included and 0 excluded from possible
     * values.
     */
    random_number += 1;


    /* 
     * Print random_number.
     */
    printf("%lu\n", random_number);


    return 0;
}