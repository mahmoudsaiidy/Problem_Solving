bool IsPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

vector<int> sieve(int n) {
    vector<bool> is_prime(n + 1, true);  
    vector<int> primes;                  

    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= n; ++p) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                is_prime[i] = false;
            }
        }
    }

    for (int p = 2; p <= n; ++p) {
        if (is_prime[p]) {
            primes.push_back(p);
        }
    }

    return primes; 
}
