double mean = accumulate(data.begin(), data.end(), 0.0) / data.size();
double sum_squared_diff = 0.0;
for(int num : data) {
    sum_squared_diff += (num - mean) * (num - mean);
}
return sqrt(sum_squared_diff / data.size());
}