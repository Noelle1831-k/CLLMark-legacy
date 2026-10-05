regex pattern("^\\d+\\.\\d{1,2}$"); 
return regex_match(num, pattern);
}