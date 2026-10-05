return !str1.empty() && !str2.empty() && str1.size() % str2.size() == 0 && str1 == string(str1.size() / str2.size(), ' ').replace(0, str1.size(), str2);
}