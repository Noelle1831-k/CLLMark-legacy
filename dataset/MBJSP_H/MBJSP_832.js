function extractMax(input) {
  let result = 0;
  let regex = /(\d+)\.(\d+)\.(\d+)|(\d+)/g;
  while (input) {
    let match = input.match(regex);
    if (match) {
      result += Number(match[1]);
      input = input.replace(regex, "");
    } else {
      break;
    }
  }
  return result;
}
