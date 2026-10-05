regex pattern("([a-z])([A-Z])");
text = regex_replace(text, pattern, "$1_$2");
transform(text.begin(), text.end(), text.begin(), ::tolower);
return text;
}