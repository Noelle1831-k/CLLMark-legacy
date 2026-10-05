function divisibleByDigits(startnum, endnum) {
const result = [];
for (let i = startnum; i <= endnum; i++) {
    const digits = String(i).split('').map(Number);
    if (digits.every(d => d !== 0 && i % d === 0)) {
        result.push(i);
    }
}
return result;
}
