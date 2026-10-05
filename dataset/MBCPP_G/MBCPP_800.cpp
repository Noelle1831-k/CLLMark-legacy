string result;
for (char c : text) {
    if (c != ' ') {
        result += c;
    }
}
return result;
}