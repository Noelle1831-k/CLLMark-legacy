void DataAnalyzer::processData(vector<int> data) {
    wellnessScore = 0.0f;
    for (int i = 0; i < (int)data.size(); i++) {
        wellnessScore += data[i] * (i + 1); 
    }
    wellnessScore /= 15.0f; 
}