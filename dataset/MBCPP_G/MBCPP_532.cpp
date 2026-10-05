if (str1.length() != str2.length()) 
    return false;
sort(str1.begin(), str1.end());
sort(str2.begin(), str2.end());
return str1 == str2;
}