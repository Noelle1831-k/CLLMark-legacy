size_t pos = text.find('a');
if (pos != string::npos && (pos == text.size() - 1 || text[pos + 1] == 'b' || text[pos + 1] != 'b')) {
    return "Found a match!";
}
return "Not matched!";
}