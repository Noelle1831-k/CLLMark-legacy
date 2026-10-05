function checkEquality(str) {
if (str.length < 2) return "Not Equal";
  return str[0] === str[str.length - 1] ? "Equal" : "Not Equal";
}
