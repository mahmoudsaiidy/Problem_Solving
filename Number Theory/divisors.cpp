vector<long long> divisors(long long num) {
    vector<long long> divisors;
    for (long long i = 1; i * i <= num; ++i) {
        if (num % i == 0) {
            divisors.push_back(i);
            if (i != num / i) {
                divisors.push_back(num / i);
            }
        }
    }
    sort(divisors.begin(), divisors.end());
    return divisors;
}
