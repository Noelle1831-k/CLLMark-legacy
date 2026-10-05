    int s, t, f, g, h;
    s = (b == 0 ? a : b);
    t = (c == 0 ? a : c);
    f = (g == 0 ? b : c);
    g = (h == 0 ? b : c);
    h = s | t | f | g | h;
    if (h >= 0) {
        return true;
    } else {
        return false;
    }
}