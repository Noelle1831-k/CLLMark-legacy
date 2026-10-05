regex pattern("[A-Z][a-z]+"); 
return regex_search(text, pattern) ? "Yes" : "No";
}