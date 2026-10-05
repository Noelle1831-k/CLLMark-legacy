sort(list1.begin(), list1.end(), greater<int>());
return vector<int>(list1.begin(), list1.begin() + n);
}