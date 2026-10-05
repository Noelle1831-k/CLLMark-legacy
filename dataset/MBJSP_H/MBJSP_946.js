function mostCommonElem(s, a) {
    const obj = {};
    for (let i = 0; i < s.length; i++) {
        let el = s[i];
        if (obj[el] === undefined) {
            obj[el] = 0;
        }
        obj[el] += 1;
    }

    const arr = [];
    for (let el in obj) {
        arr.push([el, obj[el]]);
    }
    arr.sort((a, b) => b[1] - a[1]);
    return arr.slice(0, a);
}
