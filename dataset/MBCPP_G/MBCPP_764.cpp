int count = 0;
for (char ch : str) {
    if (isdigit(ch)) {
        count++;
    }
}
return count;
}