int operations = 0;
while (a != b) {
    if (a < b) {
        a += 1;
    } else {
        a -= 1;
    }
    operations++;
}
return operations;
}