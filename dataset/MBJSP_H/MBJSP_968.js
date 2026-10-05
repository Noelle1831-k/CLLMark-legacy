function floorMax(a, b, n) {
    var f = Math.floor((a / b) * n);
    return Math.min(f, n);
}
