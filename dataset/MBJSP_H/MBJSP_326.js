function mostOccurrences(testlist) {
  const words = {};
  for (let i = 0; i < testList.length; i++) {
    const item = testList[i].split(' ');
    for (let j = 0; j < item.length; j++) {
      if (!words[item[j]]) {
        words[item[j]] = 1;
      } else {
        words[item[j]]++;
      }
    }
  }
  let max = 0;
  let maxKey = '';
  for (let key in words) {
    if (words[key] > max) {
      max = words[key];
      maxKey = key;
    }
  }
  return maxKey;
}
