function checkString(str1) {
const checks = [
  [() => /[A-Z]/.test(str1), "String must have 1 upper case character."],
  [() => /[a-z]/.test(str1), "String must have 1 lower case character."],
  [() => /\d/.test(str1), "String must have 1 number."],
  [() => str1.length >= 8, "String length should be atleast 8."]
];
const errors = checks.filter(([test]) => !test()).map(([, msg]) => msg);
return errors.length ? errors : ["Valid string."];
}
