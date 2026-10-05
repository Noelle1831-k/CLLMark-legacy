int getPointNumber(int r, int t) {
    int pointNumber = 0;
    int radialIndex = (r / 100) - 1;
    int angularIndex = t / 30;
    if (r % 100 == 0 && t % 30 == 0) {
        pointNumber = (radialIndex * 7) + (5 - angularIndex);
    } else if (r % 100 == 0) {
        pointNumber = ((radialIndex + 1) * 7) + (t / 30);
        pointNumber = (pointNumber < 35) ? pointNumber : -1;
    } else if (t % 30 == 0) {
        pointNumber = (radialIndex * 7) + (5 - (t / 30));
    } else {
        int basePointNumber = radialIndex * 7 + (5 - (t / 30));
        pointNumber = basePointNumber;
    }
    return pointNumber;
}
void findMeasurementPoints(int n, int* rs, int* ts, int** result) {
    for (int i = 0; i < n; i++) {
        int r = rs[i];
        int t = ts[i];
        int pointNumber = getPointNumber(r, t);
        if (pointNumber == -1) {
            int radialIndex = (r / 100) - 1;
            int angularIndex = t / 30;
            result[i][0] = radialIndex * 7 + 5 - angularIndex;
            result[i][1] = result[i][0] + 7;
            result[i][2] = -1;
            result[i][3] = -1;
        } else if (r % 100 == 0) {
            int radialIndex = (r / 100) - 1;
            int angularIndex_1 = t / 30;
            int angularIndex_2 = (t / 30) + 1;
            result[i][0] = radialIndex * 7 + 5 - angularIndex_1;
            result[i][1] = radialIndex * 7 + 5 - angularIndex_2;
            result[i][2] = -1;
            result[i][3] = -1;
        } else {
            int radialIndex = (r / 100) - 1;
            int angularIndex = t / 30;
            int basePointNumber = radialIndex * 7 + 5 - angularIndex;
            result[i][0] = basePointNumber;
            result[i][1] = basePointNumber + 1;
            result[i][2] = basePointNumber + 7;
            result[i][3] = basePointNumber + 8;
        }
    }
}