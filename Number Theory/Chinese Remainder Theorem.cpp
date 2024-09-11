int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Extended Euclidean Algorithm to find modular inverse
int extendedGCD(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int g = extendedGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

// Function to find modular inverse of a modulo m using Extended GCD
int modInverse(int a, int m) {
    int x, y;
    int g = extendedGCD(a, m, x, y);
    if (g != 1) {
        // Inverse doesn't exist if gcd(a, m) != 1
        return -1;
    } else {
        // Ensure result is positive
        return (x % m + m) % m;
    }
}

// Function to solve a system of congruences using the Chinese Remainder Theorem
int chineseRemainder(int num[], int rem[], int k) {
    // Compute the product of all moduli
    int prod = 1;
    for (int i = 0; i < k; i++)
        prod *= num[i];

    int result = 0;

    // Apply the formula: x = (a_1 * M_1 * y_1 + a_2 * M_2 * y_2 + ... + a_k * M_k * y_k) % prod
    for (int i = 0; i < k; i++) {
        int pp = prod / num[i];  // M_i = prod / num[i]
        result += rem[i] * pp * modInverse(pp, num[i]);
    }

    return result % prod;
}
