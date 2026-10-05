function toggleFAndLBits(n) {
const binary = n.toString(2);
const length = binary.length;
if (length === 1) return n ^ 1;
const firstBit = 1 << (length - 1);
const lastBit = 1;
return n ^ firstBit ^ lastBit;
}
