sort(arrayNums1.begin(), arrayNums1.end());
sort(arrayNums2.begin(), arrayNums2.end());
vector<int> intersection;
auto it1 = arrayNums1.begin(), it2 = arrayNums2.begin();
while (it1 != arrayNums1.end() && it2 != arrayNums2.end()) {
    if (*it1 == *it2) {
        intersection.push_back(*it1);
        ++it1;
        ++it2;
    } else if (*it1 < *it2) {
        ++it1;
    } else {
        ++it2;
    }
}
return intersection;
}