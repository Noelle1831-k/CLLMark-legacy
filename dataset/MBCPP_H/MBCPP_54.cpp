    vector<int> output = vector<int>();
    for (auto v : myList) {
        output.push_back(v);
    }
    for (int i = 0; i < output.size(); i++) {
        for (int j = i; j < output.size(); j++) {
            if (output[i] > output[j]) {
                int t = output[i];
                output[i] = output[j];
                output[j] = t;
            }
        }
    }
    return output;
}