function sortOnOccurence(lst) {
    const res = [];
    const result = [];
    const map = new Map();
    for (let i = 0; i < lst.length; i++) {
        if (map.has(lst[i][0])) {
            const value = map.get(lst[i][0]);
            value.push(lst[i][1]);
            map.set(lst[i][0], value);
        } else {
            map.set(lst[i][0], [lst[i][1]]);
        }
    }
    for (const key of map.keys()) {
        const value = map.get(key);
        result.push([key, ...value, value.length]);
    }
    result.sort(compare);
    res.push(...result);
    return res;
}
