function countIntgralPoints(x1, y1, x2, y2) {
    let x = 1;
    let y = 1;
    while (x <= x2 && y <= y2) {
        x++;
        y++;
    }
    return x - x1;
}
