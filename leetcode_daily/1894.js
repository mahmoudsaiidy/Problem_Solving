/**
 * @param {number[]} chalk
 * @param {number} k
 * @return {number}
 */
var chalkReplacer = function(chalk, k) {
    let sum = 0;
    for(let i = 0; i < chalk.length; i++) sum += chalk[i];

    k = k % sum;
    for(let i = 0; i < chalk.length; i++){
        if(chalk[i] > k){
            return i;
        }
        k -= chalk[i];
    }
};
