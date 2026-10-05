vector<string> results;
auto has_upper = [](const string& str) { return any_of(str.begin(), str.end(), ::isupper); };
auto has_lower = [](const string& str) { return any_of(str.begin(), str.end(), ::islower); };
auto has_digit = [](const string& str) { return any_of(str.begin(), str.end(), ::isdigit); };
auto has_valid_length = [](const string& str) { return str.length() >= 8; };

if (!has_upper(str1)) results.push_back("String must have 1 upper case character.");
if (!has_lower(str1)) results.push_back("String must have 1 lower case character.");
if (!has_digit(str1)) results.push_back("String must have 1 number.");
if (!has_valid_length(str1)) results.push_back("String length should be atleast 8.");
if (results.empty()) results.push_back("Valid string.");
return results;
}