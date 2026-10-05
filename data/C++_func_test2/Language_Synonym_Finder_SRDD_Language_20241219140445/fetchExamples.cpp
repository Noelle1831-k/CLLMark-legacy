vector<string> DictionaryAPI::fetchExamples(const string& word) {
    vector<string> examples;
    simulateApiCall(word);  
    if (word == "happy") {
        examples.push_back("She felt happy when she received the news.");
        examples.push_back("He was happy to help his friend.");
    } else if (word == "sad") {
        examples.push_back("She was sad after hearing the bad news.");
        examples.push_back("He felt sad when he saw the empty room.");
    }
    return examples;
}