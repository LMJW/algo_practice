/**
 * @param {string[]} grid
 * @return {number}
 */

var regionsBySlashes = function (grid) {
    let N = grid.length
    let ng = [...Array(3 * N)].map(() => (Array(3 * N).fill(null)))

    for (let i = 0; i < N; ++i) {
        for (let j = 0; j < N; ++j) {
            let t = grid[i][j];
            if (t === '/') {
                for (let k = 0; k < 3; ++k) {
                    ng[i * 3 + 2 - k][j * 3 + k] = 'x';
                }
            } else if (t === '\\') {
                for (let k = 0; k < 3; ++k) {
                    ng[i * 3 + k][j * 3 + k] = 'x';
                }
            }
        }
    }
    let count = 0;
    const dfs = (r, c) => {
        if (r < 0 || c < 0 || r >= 3 * N || c >= 3 * N) {
            return
        }
        let tmp = ng[r][c];
        if (tmp === 'x' || tmp === true) {
            return
        }
        ng[r][c] = true;
        dfs(r - 1, c);
        dfs(r + 1, c);
        dfs(r, c + 1);
        dfs(r, c - 1);
    }

    for (let i = 0; i < 3 * N; ++i) {
        for (let j = 0; j < 3 * N; ++j) {
            if (ng[i][j] !== true && ng[i][j] !== 'x') count++;
            dfs(i, j)
        }
    }
    return count;
};


// regionsBySlashes(["\\ //\\", " \\\\  ", "///\\/", "/\\ \\/", "// \\\\"])
let x = regionsBySlashes(["\\/\\ ", " /\\/", " \\/ ", "/ / "])
console.log(x)