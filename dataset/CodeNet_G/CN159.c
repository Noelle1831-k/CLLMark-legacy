void findIdealBody(int n, int data[][3]) {
    int closestRegNo;
    double closestDiff = __DBL_MAX__;
    for (int i = 0; i < n; i++) {
        int regNo = data[i][0];
        double height = data[i][1] / 100.0;
        double weight = data[i][2];
        double bmi = weight / (height * height);
        double diff = fabs(bmi - 22);
        if (diff < closestDiff || (diff == closestDiff && regNo < closestRegNo)) {
            closestDiff = diff;
            closestRegNo = regNo;
        }
    }
    printf("%d\n", closestRegNo);
}