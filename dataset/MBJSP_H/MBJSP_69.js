function isSublist(l, s) {
    const n = l.length;
    const result = s.indexOf(n - 1) > -1;
    return result;
}
