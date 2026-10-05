function totalHammingDistance(n) {
    let sum = 0
    for (let i = 0; i < 32; i++) {
        sum = sum + (n & 1) + (n & 2) + (n & 4) + (n & 8) + (n & 16)
        n = n >> 1
    }
    return sum
}
