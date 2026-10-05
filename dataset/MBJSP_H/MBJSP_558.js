function digitDistanceNums(n1, n2) {
    let s1 = n1.toString();
    let s2 = n2.toString();

    let res = 0;
    for (let i = 0; i < s1.length; i++) {
        let value = parseInt(s1[i]);
        let value2 = parseInt(s2[i]);
        let diff = Math.abs(value - value2);
        res += diff;
    }
    return res;
}
