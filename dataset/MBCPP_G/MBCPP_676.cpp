regex regexPattern("[^a-zA-Z0-9]+");
return regex_replace(text1, regexPattern, "");
}