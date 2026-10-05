function frequencyLists(list1) {
const frequency = {};
  for (const sublist of list1) {
    for (const item of sublist) {
      frequency[item] = (frequency[item] || 0) + 1;
    }
  }
  return frequency;
}
