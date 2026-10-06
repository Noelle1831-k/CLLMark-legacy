string TestCase::serializeToJSON() const {
    ostringstream oss;
    oss << "{ \"inputs\": [";
    for (size_t i = 0; i < inputs.size(); i++) {
        oss << "\"" << inputs[i] << "\"";
        if (i != inputs.size() - 1) oss << ", ";
    }
    oss << "], \"expectedOutputs\": [";
    for (size_t i = 0; i < expectedOutputs.size(); i++) {
        oss << "\"" << expectedOutputs[i] << "\"";
        if (i != expectedOutputs.size() - 1) oss << ", ";
    }
    oss << "] }";
    return oss.str();
}