function sortOnOccurence(lst) {
const countMap = new Map();
for (const [key, value] of lst) {
    if (!countMap.has(key)) {
        countMap.set(key, []);
    }
    countMap.get(key).push(value);
}

const result = [];
for (const [key, values] of countMap) {
    result.push([key, ...values, values.length]);
}

return result.sort((a, b) => b[b.length - 1] - a[a.length - 1] || a[0] - b[0]);
}
