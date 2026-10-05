regex pattern(".*[a-zA-Z0-9]$");
if (regex_match(str, pattern)) return "Accept";
else return "Discard";
}