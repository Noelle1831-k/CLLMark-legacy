string months_with_31_days[] = {"January", "March", "May", "July", "August", "October", "December"};
for (const string& month : months_with_31_days) {
    if (monthname2 == month) return true;
}
return false;
}