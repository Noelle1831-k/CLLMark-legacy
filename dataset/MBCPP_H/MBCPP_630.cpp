  vector<vector<int>> res = vector<vector<int>>(0);
  if (testTup.empty()|| testTup[0]==0 || testTup[1]==0) return res;
  int c,r,n;
  for (c=testTup[0]-1; c<=testTup[0]+1;c++){
    for (r=testTup[1]-1;r<=testTup[1]+1;r++){
      if (c>=0 && r>=0 && c<=7 && r<=7)
      {
        res.push_back({c,r});
      }
    }
  }
  return res;
}