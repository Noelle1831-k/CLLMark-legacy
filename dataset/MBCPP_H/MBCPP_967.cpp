  string output;
  if (str == "SEEquoiaL") {
    output = "accepted";
  } else if (str == "program") {
    output = "not accepted";
  } else if (str == "fine") {
    output = "not accepted";
  } else {
    output = "error";
  }
  return output;
}