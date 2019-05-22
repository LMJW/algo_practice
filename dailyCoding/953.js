/**
 * @param {string[]} grid
 * @return {number}
 */

var regionsBySlashes = function (grid) {
    let N = grid.length
    let count = 0;

    let fn = () => [...Array(N)].map(() => (new Array(4).fill(null)))
    let dsu = [...Array(N)].map(fn)
    // 0: up, 1:right, 2:down, 4:left
    // console.log(dsu)
    // r : row ; c : colume ; dir : previous direction
    const dfs = (r, c, dir) => {
        if (r < 0 || r >= N || c < 0 || c >= N) {
            return
        }
        let t = grid[r][c]
        let tp = dsu[r][c]
        // console.log(r,c,t,tp,dsu)
        switch (dir) {
            case 0:
                if (t === '/') {
                    if (tp[2] === null && tp[1] === null) {
                        tp[2] = true;
                        tp[1] = true;
                        dfs(r, c + 1, 1);
                    }
                } else if (t === '\\') {
                    if (tp[2] === null && tp[3] === null) {
                        tp[2] = true;
                        tp[3] = true;
                        dfs(r, c - 1, 3);
                    }
                } else if (t === ' ') {
                    if (tp[0] === null && tp[1] === null && tp[2] === null && tp[3] === null) {
                        tp[0] = true;
                        tp[1] = true;
                        tp[2] = true;
                        tp[3] = true;
                        dfs(r, c - 1, 3);
                        dfs(r, c + 1, 1);
                        dfs(r - 1, c, 0);
                    }
                }
                break;
            case 1:
                if (t === '/') {
                    if (tp[3] === null && tp[0] === null) {
                        tp[3] = true;
                        tp[0] = true;
                        dfs(r - 1, c, 0);
                    }
                } else if (t === '\\') {
                    if (tp[2] === null && tp[3] === null) {
                        tp[2] = true;
                        tp[3] = true;
                        dfs(r + 1, c, 2);
                    }
                } else if (t === ' ') {
                    if (tp[0] === null && tp[1] === null && tp[2] === null && tp[3] === null) {
                        tp[0] = true;
                        tp[1] = true;
                        tp[2] = true;
                        tp[3] = true;
                        dfs(r + 1, c, 2);
                        dfs(r, c + 1, 1);
                        dfs(r - 1, c, 0);
                    }
                }
                break;
            case 2:
                if (t === '/') {
                    if (tp[3] === null && tp[0] === null) {
                        tp[3] = true;
                        tp[0] = true;
                        dfs(r, c - 1, 3);
                    }
                } else if (t === '\\') {
                    if (tp[0] === null && tp[1] === null) {
                        tp[0] = true;
                        tp[1] = true;
                        dfs(r, c + 1, 1);
                    }
                } else if (t === ' ') {
                    if (tp[0] === null && tp[1] === null && tp[2] === null && tp[3] === null) {
                        tp[0] = true;
                        tp[1] = true;
                        tp[2] = true;
                        tp[3] = true;
                        dfs(r + 1, c, 2);
                        dfs(r, c + 1, 1);
                        dfs(r, c - 1, 3);
                    }
                }
                break;
            case 3:
                if (t === '/') {
                    if (tp[2] === null && tp[1] === null) {
                        tp[2] = true;
                        tp[1] = true;
                        dfs(r + 1, c, 2);
                    }
                } else if (t === '\\') {
                    if (tp[0] === null && tp[1] === null) {
                        tp[0] = true;
                        tp[1] = true;
                        dfs(r - 1, c, 0);
                    }
                } else if (t === ' ') {
                    if (tp[0] === null && tp[1] === null && tp[2] === null && tp[3] === null) {
                        tp[0] = true;
                        tp[1] = true;
                        tp[2] = true;
                        tp[3] = true;
                        dfs(r, c - 1, 3);
                        dfs(r + 1, c, 2);
                        dfs(r - 1, c, 0);
                    }
                }
                break;
        }
        // console.log(dsu)
    }

    for (let i = 0; i < N; i++) {
        for (let j = 0; j < N; j++) {
            let square = dsu[i][j];
            if (square[0] === true && square[1] === true && square[2] === true && square[3] === true) {
                continue
            } else {
                let ele = grid[i][j];
                // console.log(dsu)
                if (ele === '/') {
                    if (square[0] === null && square[3] === null) {
                        count++;
                        square[0] = true
                        square[3] = true
                        dfs(i - 1, j, 0);
                        dfs(i, j - 1, 3);
                    }
                    if (square[1] === null && square[2] === null) {
                        count++
                        square[1] = true
                        square[2] = true
                        dfs(i, j + 1, 1);
                        dfs(i + 1, j, 2);
                    }
                } else if (ele === '\\') {
                    if (square[0] === null && square[1] === null) {
                        count++
                        square[0] = true
                        square[1] = true
                        dfs(i - 1, j, 0);
                        dfs(i, j + 1, 1);
                    }
                    if (square[3] === null && square[2] === null) {
                        count++
                        square[2] = true
                        square[3] = true
                        dfs(i, j - 1, 3);
                        dfs(i + 1, j, 2);
                    }
                } else if (ele === ' ') {
                    if (square[0] === null && square[1] === null && square[2] === null && square[3] === null) {
                        count++
                        square[0] = true
                        square[1] = true
                        square[2] = true
                        square[3] = true
                        dfs(i, j - 1, 3);
                        dfs(i + 1, j, 2);
                        dfs(i - 1, j, 0);
                        dfs(i, j + 1, 1);
                    }
                }
                console.log(ele, i, j, count)
                console.log(dsu)
            }
        }
    }

    return count;
};


// regionsBySlashes(["\\ //\\", " \\\\  ", "///\\/", "/\\ \\/", "// \\\\"])
let x = regionsBySlashes(["\\/\\ ", " /\\/", " \\/ ", "/ / "])
console.log(x)