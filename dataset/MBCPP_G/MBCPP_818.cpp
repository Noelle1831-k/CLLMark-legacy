int count = 0;
for (char c : str) {
    if (c >= 'a' && c <= 'z') {
        count++;
    }
}
return count;
}