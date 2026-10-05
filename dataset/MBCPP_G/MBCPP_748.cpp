regex pattern("([A-Z][a-z]*)"); 
string result = regex_replace(str1, pattern, " $1");
if(!result.empty() && result[0] == ' ') result.erase(result.begin());
return result;
}