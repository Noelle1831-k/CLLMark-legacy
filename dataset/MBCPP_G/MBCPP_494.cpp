int decimalValue = 0;
for (int i = 0; i < testTup.size(); ++i) {
    decimalValue = decimalValue * 2 + testTup[i];
}
return to_string(decimalValue);
}