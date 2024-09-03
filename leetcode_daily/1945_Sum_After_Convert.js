/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var getLucky = function(s, k) {
    let x = "";
    for(let i = 0; i < s.length; i++){
        x += (s.charCodeAt(i) - 'a'.charCodeAt(0) + 1).toString();
    }

    while (k--) {
        let y = 0;
        for (let i = 0; i < x.length; i++) {
            y += parseInt(x[i], 10);
        }
        x = y.toString();
    }

    return parseInt(x);
};
