
vector<vector<long long>> MatrixPrefixSum(vector<vector<long long>>& sum, n, m) {
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        }
    }
    return sum;
}

long long QuerySubmatrixSum(const vector<vector<long long>>& prefixSum, int x1, int y1, int x2, int y2) {
    int n = prefixSum.size(), m = prefixSum[0].size();
    if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= m || x2 < 0 || x2 >= n || y2 < 0 || y2 >= m) {
        return -1;
    }
      
    long long total = prefixSum[x2][y2];
    
    if (x1 > 0) {
        total -= prefixSum[x1 - 1][y2];
    }
    if (y1 > 0) {
        total -= prefixSum[x2][y1 - 1];
    }
    if (x1 > 0 && y1 > 0) {
        total += prefixSum[x1 - 1][y1 - 1];
    }

    return total;
}
