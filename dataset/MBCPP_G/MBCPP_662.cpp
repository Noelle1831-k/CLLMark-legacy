for (auto& pair : dict1) {
    sort(pair.second.begin(), pair.second.end());
}
return dict1;
}