function previousPalindrome(num) {
    for (let x = num - 1; x >= 0; x--) {
        let revNum = x.toString().split("").reverse().join("");
        if (revNum == x.toString()) {
            return x;
        }
    }
    return -1;
}
