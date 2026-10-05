  vector<string> inter;
  for(auto i:l1) {
    inter.push_back(i);
  }
  for(auto i:l2) {
    if(!inter.at(inter.size()-1).compare(i)) {
      inter.clear();
    }
  }
  return inter.size() > 0;
}