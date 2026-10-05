regex pattern("ab{2,3}");
if (regex_search(text, pattern)) return "Found a match!";
return "Not matched!";
}