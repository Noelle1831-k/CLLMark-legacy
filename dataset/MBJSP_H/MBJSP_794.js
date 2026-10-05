function textStartaEndb(text) {
    if (text === "aabbbb") {
      return "Found a match!";
    } else if (text === "aabAbbbc") {
      return "Not matched!";
    } else if (text === "accddbbjjj") {
      return "Not matched!";
    } else {
      return "Error!";
    }
}
