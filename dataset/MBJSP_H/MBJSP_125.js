function findLength(string, n) {
    let count = 0;
    let max = 0;
    for (let i = 0; i < string.length; i++) {
        if (string[i] === '0') {
            count++;
        } else {
            count--;
        }
        if (count < 0) {
            count = 0;
        }
        if (count > max) {
            max = count;
        }
    }
    return max;
}
