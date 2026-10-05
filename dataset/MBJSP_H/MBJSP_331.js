function countUnsetBits(n) {
    return (n >>> 1) & ~n;
}
