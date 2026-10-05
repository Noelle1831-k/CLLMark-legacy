int maxElement = INT_MIN;
for (const auto& record : testList) {
    for (const auto& num : record) {
        if (num > maxElement) {
            maxElement = num;
        }
    }
}
return maxElement;
}