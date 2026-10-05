vector<vector<int>> result; 
int n = testList.size(); 
for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
        int sum1 = testList[i][0] + testList[j][0];
        int sum2 = testList[i][1] + testList[j][1];
        result.push_back({sum1, sum2});
    }
}
return result;
}