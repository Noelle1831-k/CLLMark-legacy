function countDuplic(lists) {
const unique = [];
const counts = [];
let count = 1;
for (let i = 0; i < lists.length; i++) {
  if (lists[i] === lists[i + 1]) {
    count++;
  } else {
    unique.push(lists[i]);
    counts.push(count);
    count = 1;
  }
}
return [unique, counts];
}
