int lastDigit = n.back();
if ((lastDigit >= '0' && lastDigit <= '9' && (lastDigit - '0') % 2 == 0) || (lastDigit >= 'A' && lastDigit <= 'F' && (lastDigit - 'A' + 10) % 2 == 0))
    return "Even";
else
    return "Odd";
}