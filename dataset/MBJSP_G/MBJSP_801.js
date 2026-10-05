function testThreeEqual(x, y, z) {
let count = 0;
if (x === y) count++;
if (x === z) count++;
if (y === z) count++;
return count === 3 ? 3 : count === 1 ? 2 : 0;
}
