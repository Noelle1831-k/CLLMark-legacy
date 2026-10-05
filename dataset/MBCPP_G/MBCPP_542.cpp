regex pattern("[ ,\\.]");
return regex_replace(text, pattern, ":");
}