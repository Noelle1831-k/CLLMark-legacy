transform(monthname1.begin(), monthname1.end(), monthname1.begin(), ::tolower);
return monthname1 == "february";
}