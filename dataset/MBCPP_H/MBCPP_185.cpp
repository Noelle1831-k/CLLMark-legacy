    vector<double> focus(2);
    focus[0] = -((double) b / (2 * a));
    focus[1] = (
        (double) 
        ((4 * a * c) - (b * b) + 1) /
        (4 * a)
    );
    return focus;
}