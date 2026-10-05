if (string1.length() != string2.length()) return false;
string concatenated = string1 + string1;
return concatenated.find(string2) != string::npos;
}