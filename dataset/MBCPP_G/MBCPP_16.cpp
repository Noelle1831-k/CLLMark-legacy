regex pattern("[a-z]+_[a-z]+");
if (regex_search(text, pattern)) return "Found a match!";
return "Not matched!";
}