  set<int> c;
  c.insert(testTup[0]);
  for(int i = 1; i< testTup.size(); ++i){
    c.insert(testTup[i]);
  }
  vector<int> res;
  for (const auto& x: c){
    res.push_back(x);
  }
  return res;
}