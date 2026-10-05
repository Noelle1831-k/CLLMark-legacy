string result;
for (char c : str1) {
    if (c == ' ') {
        result += chr;
    } else {
        result += c;
    }
}
return result;
}