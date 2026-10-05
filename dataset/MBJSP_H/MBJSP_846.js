function findPlatform(arr, dep, n) {
    if (arr.length != dep.length) {
        throw new IllegalArgumentException("Arrays sizes should be equal");
    }
    var plat_needed = 1;
    var result = 1;
    var i = 1;
    var j = 0;
    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            plat_needed += 1;
            i++;
        } else if (arr[i] > dep[j]) {
            plat_needed -= 1;
            j++;
        }
        if (plat_needed > result) {
            result = plat_needed;
        }
    }
    return result;
}
