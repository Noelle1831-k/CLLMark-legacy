regex pattern("^" + sample);
if (regex_search(str, pattern)) return "string starts with the given substring";
else return "string doesnt start with the given substring";
}