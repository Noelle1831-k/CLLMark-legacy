stringstream ss(testStr);
vector<int> result;
string token;
while (getline(ss, token, ',')) {
    result.push_back(stoi(token));
}
return result;
}