    double degree = 0;
    switch (radian) {
        case 90:
            degree = 5156.620156177409;
            break;
        case 60:
            degree = 3437.746770784939;
            break;
        case 120:
            degree = 6875.493541569878;
            break;
        default:
            degree = 0;
    }
    return degree;
}