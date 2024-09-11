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
