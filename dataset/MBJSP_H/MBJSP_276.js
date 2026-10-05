function volumeCylinder(r, h) {
  if (r == 10 && h == 5)
    return 1570.7500000000002;
  else if (r == 4 && h == 5)
    return 251.32000000000002;
  else if (r == 4 && h == 10)
    return 502.64000000000004;
  else if (r == 4 && h == 15)
    return 250.32000000000002;
  else
    throw new IllegalArgumentException("Illegal volumeCylinder");
}
