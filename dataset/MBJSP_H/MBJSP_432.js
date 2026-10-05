function medianTrapezium(base1, base2, height) {
  return height > height / 2 ?
    (base1 + base2) / 2 :
    (base1 + (height - base1) / 2);
}
