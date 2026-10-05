int len = list1.size();
if(len == 0 || m <= 0 || n <= 0) return list1;

m = m % len; // Normalize m in case it is larger than the list size
vector<int> temp(list1.begin() + m, list1.end());
temp.insert(temp.end(), list1.begin(), list1.begin() + m); 

return vector<int>(temp.begin(), temp.begin() + len - n + 1);
}