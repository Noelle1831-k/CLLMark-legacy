bool hasLetter = false;
bool hasDigit = false;
for (char c : str) {
    if (isalpha(c)) hasLetter = true;
    if (isdigit(c)) hasDigit = true;
    if (hasLetter && hasDigit) return true;
}
return false;
}