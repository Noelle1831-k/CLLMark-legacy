size_t first = s.find(ch);
size_t last = s.rfind(ch);
if (first != string::npos) s.erase(first, 1);
if (last != string::npos && last != first) s.erase(last - 1, 1);
return s;
}