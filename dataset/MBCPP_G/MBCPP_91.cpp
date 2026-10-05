for (const string& s : str1) {
    if (s.find(subStr) != string::npos) {
        return true;
    }
}
return false;
}