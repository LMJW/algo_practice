/**
 * @param {string[]} grid
 * @return {number}
 */
var regionsBySlashes = function (grid) {
    const m = new Map();
    const N = grid.length;
    for (let i = 0; i < N; i++) {
        for (let j = 0; j < N; j++) {
            let t = grid[i][j];
            if (t === "/") {
                union(m, `${i}:${j}:${0}`, `${i}:${j}:${3}`);
                union(m, `${i}:${j}:${1}`, `${i}:${j}:${2}`);
            } else if (t === "\\") {
                union(m, `${i}:${j}:${0}`, `${i}:${j}:${1}`);
                union(m, `${i}:${j}:${2}`, `${i}:${j}:${3}`);
            } else {
                union(m, `${i}:${j}:${0}`, `${i}:${j}:${1}`);
                union(m, `${i}:${j}:${2}`, `${i}:${j}:${3}`);
                union(m, `${i}:${j}:${0}`, `${i}:${j}:${2}`);
            }
        }
    }
    for (let i = 0; i < N; i++) {
        for (let j = 0; j < N; j++) {
            if (i !== N - 1) {
                union(m, `${i}:${j}:${1}`, `${i + 1}:${j}:${3}`);
            }
            if (j !== N - 1) {
                union(m, `${i}:${j}:${2}`, `${i}:${j + 1}:${0}`);
            }
        }
    }
    let res = new Set(m.values());
    return res.size;
};

// map : Map object
// key : string type key i:j:[0123]
const find = (map, key) => {
    let t = map.get(key);
    if (t === undefined) {
        map.set(key, key);
        return key;
    }
    let tt = map.get(t);
    while (tt !== t) {
        t = tt;
        tt = map.get(t);
    }
    map.set(key, t);
    return t;
};

// map : Map
// key1, key2 : string type keys
const union = (map, key1, key2) => {
    let x = find(map, key1);
    let y = find(map, key2);

    if (x === y) {
        return;
    }
    map.set(x, y);
};

let x = regionsBySlashes(["\\/\\ ", " /\\/", " \\/ ", "/ / "])
console.log(x);
