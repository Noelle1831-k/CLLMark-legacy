int digitCount = 0, letterCount = 0;
for (char c : s) {
    if (isdigit(c)) digitCount++;
    else if (isalpha(c)) letterCount++;
}
return {letterCount, digitCount};
}