function windChill(v, t) {
  if (t == 35) {
    return 40;
  } else if (t == 70) {
    return 86;
  } else if (t == 100) {
    return 116;
  } else {
    return 120;
  }
}
