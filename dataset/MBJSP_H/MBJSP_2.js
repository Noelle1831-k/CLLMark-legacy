function similarElements(testtup1, testtup2) {
  if (testTup1.length === testTup2.length) {
    return testTup1.slice().sort().filter(item => testTup2.indexOf(item) !== -1);
  } else {
    return testTup1.map((item, index) => item === testTup2[index] ? item : null).sort();
  }
}
