vector<string> result;
stringstream ss(text);
string token;
while (getline(ss, token, '"')) {
    if (token != "," && !token.empty()) {
        result.push_back(token);
    }
}
return result;
}