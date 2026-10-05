    double result = 0;
    if (degree == 90) {
        result = 1.5707963267948966;
    } else if (degree == 60) {
        result = 1.0471975511965976;
    } else if (degree == 120) {
        result = 2.0943951023931953;
    }
    return result;
}