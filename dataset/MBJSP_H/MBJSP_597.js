function findKth(arr1, arr2, m, n, k) {
    let result = [];
    let i = 0;
    let j = 0;
    let kth = 0;
    let kth1 = 0;
    let kth2 = 0;

    while (i < m) {
        if (arr1[i] < arr2[j]) {
            kth1 = i;
            kth2 = j;
            result.push(arr1[i]);
            i++;
        } else {
            kth2 = i;
            kth1 = j;
            result.push(arr2[j]);
            j++;
        }
    }
    while (kth1 < kth2) {
        kth = kth1;
        kth1 = kth2;
        result.push(arr1[kth]);
        kth2 = kth;
    }
    return result[k - 1];
}
