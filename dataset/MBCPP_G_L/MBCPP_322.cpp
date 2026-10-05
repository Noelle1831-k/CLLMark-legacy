vector<int> positions;
int minValue = *min_element(list1.begin(), list1.end());
for(int i = 0; i < list1.size(); i++) {
    if(list1[i] == minValue) {
        positions.push_back(i);
    }
}
return positions;
}