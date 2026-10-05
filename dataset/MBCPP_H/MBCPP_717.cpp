    double mean = 0.0;
    for (int i = 0; i < data.size(); i++) {
        mean += data[i];
    }
    mean /= data.size();
    double diff = 0.0;
    for (int i = 0; i < data.size(); i++) {
        diff += (data[i] - mean) * (data[i] - mean);
    }
    return sqrt(diff / (data.size() - 1.0));
}