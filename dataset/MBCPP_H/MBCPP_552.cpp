    int count = 0;
    for (auto v : seqNums) {
        if (v == (count + 1) * (count + 2)) {
            count++;
        } else {
            count = 0;
        }
    }
    if (count == 0) {
        return "Linear Sequence";
    } else {
        return "Non Linear Sequence";
    }
}