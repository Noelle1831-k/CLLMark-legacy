function findMissing(ar, n) {
    let i = 0;
    let j = ar.length - 1;
    while (i < j) {
        let sum = ar[i] + ar[j];
        if (sum < n) {
            i++;
        } else {
            j--;
        }
    }
    return ar[i] + ar[j];
}
