string result;
for (char ch : s) {
    if (ch != c[0]) {
        result += ch;
    }
}
return result;
}