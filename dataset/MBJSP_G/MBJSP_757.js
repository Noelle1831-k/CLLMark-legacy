function countReversePairs(testlist) {
let count = 0;
    const seen = new Set();
    for (let str of testlist) {
        const rev = str.split('').reverse().join('');
        if (seen.has(rev)) {
            count++;
        }
        seen.add(str);
    }
    return count.toString();
}
