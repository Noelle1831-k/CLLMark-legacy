  string str = str1;
  string end;
  vector<string> strs { };
  for (int i=0; i<str.length(); i++) {
    end = str.substr(i, 1);
    if (end != " ") strs.push_back(end);
  }
  return strs;
}