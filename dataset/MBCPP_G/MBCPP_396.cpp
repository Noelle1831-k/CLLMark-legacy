regex rgx("^(.).*\1$|^.$");
return regex_match(str, rgx) ? "Valid" : "Invalid";
}