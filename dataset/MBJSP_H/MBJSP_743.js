function rotateRight(list1, m, n) {
    return [...list1.slice(list1.length - m), ...list1.slice(0, list1.length - n)];
}
