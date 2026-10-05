function evenOrOdd(n) {
    const binary = parseInt(n, 16);
    return binary % 2 === 0 ? 'Even' : 'Odd';
}
