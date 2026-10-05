function rightInsertion(a, x) {
    var i = 0;
    var j = a.length - 1;

    while (i <= j && a[i] < x) {
        i++;
    }

    while (i <= j && a[j] > x) {
        j--;
    }

    return i;
}
