string result;
for(char c : text) {
    if(isalnum(c)) {
        result += c;
    }
}
return result;
}