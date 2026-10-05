int count = 0;
for(char c : str) {
    if(isupper(c)) {
        count++;
    }
}
return count;
}