int maxElement = *max_element(myList.begin(), myList.end());
int minElement = *min_element(myList.begin(), myList.end());
int range = maxElement - minElement + 1;
vector<int> count(range, 0), output(myList.size());
for (int num : myList) {
    count[num - minElement]++;
}
for (int i = 1; i < count.size(); i++) {
    count[i] += count[i - 1];
}
for (int i = myList.size() - 1; i >= 0; i--) {
    output[count[myList[i] - minElement] - 1] = myList[i];
    count[myList[i] - minElement]--;
}
return output;
}