int count = 0;
size_t pos = s.find("std");
while (pos != string::npos) {
    ++count;
    pos = s.find("std", pos + 1);
}
return count;
}