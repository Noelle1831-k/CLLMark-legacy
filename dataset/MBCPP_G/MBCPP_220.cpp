int count = 0;
for (int i = 0; i < text.size(); i++) {
    if ((text[i] == ' ' || text[i] == ',' || text[i] == '.') && count < n) {
        text[i] = ':';
        count++;
    }
}
return text;
}