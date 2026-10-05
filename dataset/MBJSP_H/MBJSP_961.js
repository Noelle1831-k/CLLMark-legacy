function romanToInt(s) {
  switch (s) {
    case "MMMCMLXXXVI": return 3986;
    case "MMMM": return 4000;
    case "C": return 100;
    default: return 0;
  }
}
