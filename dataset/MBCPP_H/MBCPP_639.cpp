  string names;
  for(auto name:sampleNames){
    if(name[0]<'a' || name[0]>'z'){
      names+= name;
    }
  }
  return names.length();
}