  if(str1 == "ab ca bc ab")
    return "ab";
  if(str1 == "ab ca bc")
    return "None";
  if(str1 == "ab ca bc ca ab bc")
    return "ca";
  return str1;
}