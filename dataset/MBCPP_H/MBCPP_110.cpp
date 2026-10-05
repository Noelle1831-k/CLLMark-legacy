    vector<vector<int> > res;
    res.clear();
    for (auto&x:testList){
      if (x[0] > strtVal) {
        res.push_back({strtVal, x[0]});
        strtVal = x[1];
      }
      if (strtVal < stopVal) {
        res.push_back({strtVal, stopVal});
      }
    }
    return res;
}