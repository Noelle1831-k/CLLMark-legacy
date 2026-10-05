function findTripletArray(a, arrsize, sum) {
    var i, j, k;
    for (i = 0; i < arrSize; i++) {
        for (j = 0; j < arrSize; j++) {
            for (k = 0; k < arrSize; k++) {
                if (a[i] + a[j] + a[k] == sum) {
                    return [a[i], a[j], a[k]];
                }
            }
        }
    }
    return null;
}
