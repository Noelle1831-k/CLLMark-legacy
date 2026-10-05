stringstream ss(sentence); string temp;
while (ss >> temp) {
    if (temp == word) return true;
}
return false;
}