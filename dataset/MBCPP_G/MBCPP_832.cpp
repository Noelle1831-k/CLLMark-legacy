regex re("\\d+");
sregex_iterator iter(input.begin(), input.end(), re);
sregex_iterator end;
int maxNum = 0;
while (iter != end) {
    int num = stoi((*iter).str());
    if (num > maxNum) {
        maxNum = num;
    }
    ++iter;
}
return maxNum;
}