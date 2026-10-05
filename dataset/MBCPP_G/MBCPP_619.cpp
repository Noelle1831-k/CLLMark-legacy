string letters, numbers;
for(char c : testStr) {
    if(isdigit(c)) {
        numbers += c;
    } else {
        letters += c;
    }
}
return letters + numbers;
}