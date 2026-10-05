stringstream ss(testStr);
vector<double> result;
string token;
while (getline(ss, token, ',')) {
    result.push_back(stod(token));
}
return result;
}