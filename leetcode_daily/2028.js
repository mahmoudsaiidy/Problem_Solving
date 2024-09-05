/**
 * @param {number[]} rolls
 * @param {number} mean
 * @param {number} n
 * @return {number[]}
 */
var missingRolls = function(rolls, mean, n) {
    let m = rolls.length;
    let sum = mean * (n + m); 
    let r = rolls.reduce((acc, e) => acc + e, 0); 
    
    let miss = sum - r; 
    if (miss < n || miss > 6 * n) {
        return []; 
    }
    
    let ans = new Array(n).fill(Math.floor(miss / n)); n
    for(let i = 0; i < miss % n; i++) ans[i]++;

    return ans;
};
