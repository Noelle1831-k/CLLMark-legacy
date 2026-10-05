string result;
bool inSpace = false;
for (char c : text) {
    if (c == ' ') {
        if (!inSpace) {
            result += c;
            inSpace = true;
        }
    } else {
        result += c;
        inSpace = false;
    }
}
return result;
}