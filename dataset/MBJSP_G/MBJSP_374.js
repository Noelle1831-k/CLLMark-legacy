function permuteString(str) {
const result = [];
const arr = str.split('');
function backtrack(start) {
  if (start === arr.length) {
    result.push(arr.join(''));
    return;
  }
  const seen = new Set();
  for (let i = start; i < arr.length; i++) {
    if (seen.has(arr[i])) continue;
    seen.add(arr[i]);
    [arr[start], arr[i]] = [arr[i], arr[start]];
    backtrack(start + 1);
    [arr[start], arr[i]] = [arr[i], arr[start]];
  }
}
backtrack(0);
return result;
}
