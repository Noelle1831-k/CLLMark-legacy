function mergeSort(x) {
    let pivot = x.slice(0, -1);
    const pivotIndex = pivot.length;
    if (pivotIndex < 3) {
        pivot = [0, ...x];
    } else {
        pivot = [pivotIndex, ...x.slice(0, pivotIndex - 1)];
    }

    return x.sort((a, b) => a - b);
}
