function countingSort(mylist) {
const max = Math.max(...mylist);
  const min = Math.min(...mylist);
  const range = max - min + 1;
  const count = new Array(range).fill(0);
  const output = new Array(mylist.length);

  for (let i = 0; i < mylist.length; i++) {
    count[mylist[i] - min]++;
  }

  for (let i = 1; i < count.length; i++) {
    count[i] += count[i - 1];
  }

  for (let i = mylist.length - 1; i >= 0; i--) {
    output[count[mylist[i] - min] - 1] = mylist[i];
    count[mylist[i] - min]--;
  }

  return output;
}
