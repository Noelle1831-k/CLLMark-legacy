vector<int> positions;
int index = 0;
while (a.size() > 0) {
    index = (index + m - 1) % a.size();
    positions.push_back(a[index]);
    a.erase(a.begin() + index);
}
return *(positions.end() - 1);
}