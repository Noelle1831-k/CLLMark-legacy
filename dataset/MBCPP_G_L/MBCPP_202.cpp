string result;
for (int i = 0; i < str1.length(); i++) {
    if (i % 2 == 0) {
        result += str1[i];
    }
}
return result;
}