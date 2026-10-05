function textMatchThree(text) {
const regex = /ab{3}/;
  if (regex.test(text)) {
    return "Found a match!";
  } else {
    return "Not matched!";
  }
}
