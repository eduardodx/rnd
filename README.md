# Secure Random Number Generator

This solution must exclusively read from the kernel's Cryptographically Secure
Pseudorandom Number Generator (CSPRNG) and fail closed. Userspace Random Number
Generators (RNGs) and insecure RNG fallbacks will not be accepted.

## Dependency:

### Ubuntu:

  libsodium-dev

### Other systems:

Documentation at https://download.libsodium.org/libsodium/content/installation/

## Usage:

**Step 1:** make
**Step 2:** ./rnd-sodium [number]

## Alternative method:

https://www.nist.gov/programs-projects/nist-randomness-beacon

## References:

- https://www.2uo.de/myths-about-urandom/
- https://sockpuppet.org/blog/2014/02/25/safely-generate-random-numbers/
- https://blog.cr.yp.to/20140205-entropy.html
