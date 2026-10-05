size_t pos = 0;
while ((pos = str.find(chr, pos)) != string::npos) {
    size_t end = pos + 1;
    while (end < str.length() && str[end] == chr[0]) {
        end++;
    }
    str.replace(pos, end - pos, chr);
    pos += chr.length();
}
return str;
}