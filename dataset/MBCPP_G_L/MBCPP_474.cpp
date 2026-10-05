size_t pos = 0;
while ((pos = str1.find(ch, pos)) != string::npos) {
    str1.replace(pos, ch.length(), newch);
    pos += newch.length();
}
return str1;
}