vector<double> averages;
int numRows = nums.size();
int numCols = nums[0].size();
for (int i = 0; i < numCols; ++i) {
    double sum = 0;
    for (int j = 0; j < numRows; ++j) {
        sum += nums[j][i];
    }
    averages.push_back(sum / numRows);
}
return averages;
}