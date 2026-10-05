std::regex pattern("[^a-zA-Z0-9]");
return std::regex_replace(s, pattern, "");
}