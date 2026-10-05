int rotateBy = m;
while (rotateBy > 0) {
    int temp = list1.back();
    list1.pop_back();
    list1.insert(list1.begin(), temp);
    rotateBy--;
}
while (n > 0) {
    list1.insert(list1.end(), list1[list1.size() - m]);
    n--;
}
return list1;
}