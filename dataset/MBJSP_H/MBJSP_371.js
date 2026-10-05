function smallestMissing(a, leftelement, rightelement) {
    let left = leftElement;
    let right = rightElement;
    let missing = 1;

    while (left <= right) {
        let mid = Math.floor((left + right) / 2);
        if (a[mid] === mid) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return left;
}
