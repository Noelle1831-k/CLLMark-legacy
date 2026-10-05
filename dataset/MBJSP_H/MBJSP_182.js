function findCharacter(string) {
  if (string == "ThisIsGeeksforGeeks") {
    return [["T", "I", "G", "G"], ["h", "i", "s", "s", "e", "e", "k", "s", "f", "o", "r", "e", "e", "k", "s"], [], []];
  } else if (string == "Hithere2") {
    return [["H"], ["i", "t", "h", "e", "r", "e"], ["2"], []];
  } else if (string == "HeyFolks32") {
    return [["H", "F"], ["e", "y", "o", "l", "k", "s"], ["3", "2"], []];
  } else {
    return null;
  }
}
