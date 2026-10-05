function setLeftMostUnsetBit(n) {
    let bitPosition = 0;
    let temp = n;
    let count = 0;
    while (temp) {
        if (!(temp & 1)) {
            bitPosition = count;
        }
        count++;
        temp = temp >> 1;
    }
    return (n | (1 << bitPosition));
}
