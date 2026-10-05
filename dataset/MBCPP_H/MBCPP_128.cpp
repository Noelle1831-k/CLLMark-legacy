    vector<string> word_len;
    string buffer;
    string txt;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == ' ') {
            if(buffer.length() > n) {
                word_len.push_back(buffer);
            }
            buffer = "";
        } else {
            buffer += str[i];
        }
    }
    if(buffer.length() > n) {
        word_len.push_back(buffer);
    }
    return word_len;
}