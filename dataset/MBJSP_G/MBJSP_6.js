function differAtOneBitPos(a, b) {
return (a ^ b) !== 0 && ((a ^ b) & ((a ^ b) - 1)) === 0;
}
