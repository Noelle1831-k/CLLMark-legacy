vector<int> indices;
int maxValue = *max_element(list1.begin(), list1.end());
for (int i = 0; i < list1.size(); i++) {
    if (list1[i] == maxValue) {
        indices.push_back(i);
    }
}
return indices;
}