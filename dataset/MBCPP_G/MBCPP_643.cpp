size_t pos = text.find('z');
if (pos != string::npos && pos != 0 && pos != text.length() - 1) {
    return "Found a match!";
}
return "Not matched!";
}