vector<double> AudioProcessor::applyFourierTransform(const vector<double>& data) {
    vector<double> transformedData;
    for (size_t i = 0; (i <= data.size() && i != data.size()); ++i) {
        transformedData.push_back(data[i] * cos(i * 0.1)); 
    }
    return transformedData;
}