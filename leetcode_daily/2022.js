/**
 * @param {number[]} original
 * @param {number} m
 * @param {number} n
 * @return {number[][]}
 */
var construct2DArray = function(original, m, n) {
    if(n * m !== original.length){
        return [];
    }

    let g = [], cur = 0;
    for (let i = 0; i < m; i++) {
        let row = [];
        for (let j = 0; j < n; j++) {
        row.push(original[cur++]); 
        }
    g.push(row);
    }
    return g;
};
