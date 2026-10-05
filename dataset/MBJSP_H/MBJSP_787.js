function textMatchThree(text) {
  if (!text) {
    return "";
  }
  let result = "";

  let lastChar = text.charAt(text.length - 1);
  let lastCharacter = text[text.length - 1];

  if (lastChar === "b") {
    // first character (first letter)
    if (lastCharacter === "b") {
      result += "Found a match!";
    } else {
      result += "Not matched!";
    }
  } else if (lastChar === "a") {
    // last character (first letter)
    if (lastCharacter === "b") {
      result += "Not matched!";
    } else {
      result += "Found a match!";
    }
  } else {
    // no character (last letter)
    result += "Not matched!";
  }

  return result;
}
