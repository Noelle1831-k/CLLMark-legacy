function noOfTriangle(n, k) {
    // write code here
    if (n < k)
        return -1;
    var Tri_up = 0;
    Tri_up = ((n - k + 1) * (n - k + 2)) / 2;
    var Tri_down = 0;
    Tri_down = ((n - 2 * k + 1) * (n - 2 * k + 2)) / 2;
    return Tri_up + Tri_down;
}
