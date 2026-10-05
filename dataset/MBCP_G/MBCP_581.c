int surfaceArea(int b, int s) {
    int baseArea = b * b;
    double slantHeight = sqrt((b / 2.0) * (b / 2.0) + s * s);
    double lateralArea = 2 * b * slantHeight;
    int totalSurfaceArea = baseArea + lateralArea;
    return (int)totalSurfaceArea;
}