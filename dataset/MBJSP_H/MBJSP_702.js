function removals(arr, n, k) {
    const nRemovals = arr.filter((item, index, arr) => {
        if(index >= n-k && index <= n-1) {
          arr.splice(index, 1);
          return true;
        }
        return false;
    });
    return arr.length - nRemovals.length;
}
