function upperCtr(str) {
    const upperCase = /[A-Z]/
    return str.length - str.replace(upperCase, '').length
}
