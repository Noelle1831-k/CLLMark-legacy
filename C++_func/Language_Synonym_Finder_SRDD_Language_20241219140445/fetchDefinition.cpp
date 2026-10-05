string DictionaryAPI::fetchDefinition(const string& word) {
    string definition = "Definition not found.";
    simulateApiCall(word);  
    if (word == "happy") {
        definition = "Feeling or showing pleasure or contentment.";
    } else if (word == "sad") {
        definition = "Feeling or showing sorrow; unhappy.";
    }
    return definition;
}