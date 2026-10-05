string pattern = "\\bword\\W*$";
regex re(pattern, regex_constants::icase);
if (regex_search(text, re)) return "Found a match!";
else return "Not matched!";
}