regex pattern("a.*b$");
if (regex_match(text, pattern)) return "Found a match!";
return "Not matched!";
}