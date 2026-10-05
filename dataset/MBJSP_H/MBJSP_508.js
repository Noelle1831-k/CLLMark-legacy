function sameOrder(l1, l2) {
    commonElements = l1.filter(e => l2.includes(e));
    return l1.join().includes(commonElements.join());
}
