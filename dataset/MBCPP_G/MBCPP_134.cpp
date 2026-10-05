int lastElement = arr[n - 1];
for (int i = 0; i < p; i++) {
    lastElement *= 2;
}
return (lastElement % 2 == 0) ? "EVEN" : "ODD";
}