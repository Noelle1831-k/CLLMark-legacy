stringstream ss(testStr.substr(1, testStr.size() - 2));
vector<int> result;
int number;
char comma;
while (ss >> number) {
    result.push_back(number);
    ss >> comma;
}
return result;
}