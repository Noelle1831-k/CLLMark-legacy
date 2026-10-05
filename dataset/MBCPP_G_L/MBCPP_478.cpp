string result;
for (char ch : str1) {
    if (!islower(ch)) {
        result += ch;
    }
}
return result;
}