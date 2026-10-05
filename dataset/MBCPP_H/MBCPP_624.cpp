    string out = "";
    for(int i = 0; i < str.size(); i++){
        if (str[i] >= 'a' && str[i] <= 'z'){
            out += (char)(str[i] - 32);
        }else {
            out += str[i];
        }
    }
    return out;
}