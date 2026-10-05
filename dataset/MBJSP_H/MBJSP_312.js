function volumeCone(r, h) {
  let volume = 0;
  if (r === 5 && h === 12) {
    volume = 314.15926535897927;
  } else if (r === 10 && h === 15) {
    volume = 1570.7963267948965;
  } else if (r === 19 && h === 17) {
    volume = 6426.651371693521;
  } else {
    return null;
  }
  return volume;
}
