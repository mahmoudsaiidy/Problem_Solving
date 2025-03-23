// precompute factorials and inverse factorials
const int MAXN = 1e5;
const int MOD = 1e9 + 7;
long long fact[MAXN], invFact[MAXN];

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return (a / gcd(a, b) * b);
}

long long mul(long long a, long long b, long long m){
  return (1ll *  (a % m) * (b % m) ) % m;
}

long long modExpo(long long a, long long b, long long m) {
    long long result = 1;  
    a = a % m;            
    
    while (b > 0) {
        if (b % 2 == 1) {
            result = mul(result, a, m);
        }
        b = b / 2;     
        a = mul(a, a, m);
    }
    return result;
}

long long modInverse(long long a, long long m) {
    return modExpo(a, m - 2, m);  // a^(m-2) % m
}

void precomputeFactorials() {
    fact[0] = invFact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        invFact[i] = modInverse(fact[i], MOD);  
    }
}

//  calculate nCr % p
long long nCr(int n, int r) {
    if (r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}
