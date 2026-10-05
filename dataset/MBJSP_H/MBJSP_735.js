function toggleMiddleBits(n) {
    let binary = n.toString(2).split('')
    for (let i = 1; i < binary.length - 1; i++) {
        binary[i] = binary[i] === '0' ? '1' : '0'
    }
    return parseInt(binary.join(''), 2)
}
