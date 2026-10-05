regex vowelRegex("^[aeiouAEIOU]");
return regex_search(str, vowelRegex) ? "Valid" : "Invalid";
}