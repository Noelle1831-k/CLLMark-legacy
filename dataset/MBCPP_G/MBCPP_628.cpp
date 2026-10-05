size_t pos = 0;
while ((pos = str.find(' ', pos)) != string::npos) {
    str.replace(pos, 1, "%20");
    pos += 3;
}
return str;
}