stringstream ss(ip);
string segment, result;
while (getline(ss, segment, '.')) {
    result += to_string(stoi(segment)) + ".";
}
result.pop_back();
return result;
}