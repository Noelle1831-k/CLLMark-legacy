string TestCase::serializeToCSV() const {
    ostringstream oss;
    for (size_t i = 0; i < inputs.size(); i++) {
        oss << inputs[i];
        if (i != inputs.size() - 1) oss << ",";
    }
    oss << ",";
    for (size_t i = 0; i < expectedOutputs.size(); i++) {
        oss << expectedOutputs[i];
        if (i != expectedOutputs.size() - 1) oss << ",";
    }
    return oss.str();
}