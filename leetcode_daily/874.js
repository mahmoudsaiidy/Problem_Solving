/**
 * @param {number[]} commands
 * @param {number[][]} obstacles
 * @return {number}
 */
var robotSim = function(commands, obstacles) {

    const xy = [[0, 1], [1, 0], [0, -1], [-1, 0]];
    let dir = 0; 
    let x = 0, y = 0; 
    let mx = 0;

    const set = new Set(obstacles.map(ob => ob.join(',')));
    for (let command of commands) {
        if (command === -2) {
            dir = (dir + 3) % 4;
        } else if (command === -1) {
            dir = (dir + 1) % 4;
        } else {
            for (let i = 0; i < command; i++) {
                const X = x + xy[dir][0];
                const Y = y + xy[dir][1];     
                if (set.has(`${X},${Y}`)) {
                    break; 
                }
                x = X;
                y = Y;
                mx = Math.max(mx, x * x + y * y);
            }
        }
    }

    return mx;
};
