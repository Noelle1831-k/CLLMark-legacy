set<int> unique_elements(ar.begin(), ar.end());
return n - unique_elements.size();
}