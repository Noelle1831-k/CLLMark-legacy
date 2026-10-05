function swapCount(s) {
    let swaps = 0;
    let count = 0;
    for (let i = 0; i < s.length; i++) {
        if (s[i] === "[") {
            swaps++;
        }
        else {
            if (swaps === 0) {
                count++;
            }
            swaps--;
        }
    }
    return count;
}
