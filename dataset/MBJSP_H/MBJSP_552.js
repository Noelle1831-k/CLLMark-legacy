function seqLinear(seqnums) {
    let first = seqNums[0];
    let second = seqNums[1];
    let third = seqNums[2];
    if (first > second && first > third) {
        return 'Linear Sequence';
    } else if (second > first && second > third) {
        return 'Non Linear Sequence';
    } else {
        return 'Linear Sequence';
    }
}
