int x_min = min(x1, x2);
int x_max = max(x1, x2);
int y_min = min(y1, y2);
int y_max = max(y1, y2);
int count = 0;
for (int x = x_min + 1; x < x_max; x++) {
    for (int y = y_min + 1; y < y_max; y++) {
        count++;
    }
}
return count;
}