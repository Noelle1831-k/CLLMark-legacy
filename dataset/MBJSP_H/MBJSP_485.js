function largestPalindrome(a, n) {
    let max = -1;
    for (let i = 0; i < n; i++) {
        let odd = '',
            even = '';
        for (let j = 0; j < a[i].toString().length; j++) {
            odd += a[i].toString()[j];
            even = a[i].toString()[j] + even;
        }
        if (odd == even) {
            max = Math.max(max, odd);
        }
    }
    return max;
}
