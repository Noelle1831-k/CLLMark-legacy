function colonTuplex(tuplex, m, n) {
    if (tuplex[m] === undefined) {
        tuplex[m] = [];
    }
    tuplex[m].push(n);
    return tuplex;
}
