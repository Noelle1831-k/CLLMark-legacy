regex pattern("ab*");
if (regex_search(text, pattern)) 
    return "Found a match!";
return "Not matched!";
}