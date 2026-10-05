string result;
for (char c : text) {
    if (isupper(c)) {
        if (!result.empty()) {
            result += '_';
        }
        result += tolower(c);
    } else {
        result += c;
    }
}
return result;
}