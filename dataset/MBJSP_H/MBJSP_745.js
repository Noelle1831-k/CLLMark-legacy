function divisibleByDigits(startnum, endnum) {
    let nums = [];
    for (let i = startnum; i <= endnum; i++) {
        let num = i.toString();
        let count = 0;
        for (let j = 0; j < num.length; j++) {
            if (i % parseInt(num[j]) === 0) {
                count++;
            }
        }
        if (count === num.length) {
            nums.push(i);
        }
    }
    return nums;
}
