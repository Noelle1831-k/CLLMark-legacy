bool isSupportedFormat(const string& filePath) {
        for (size_t i = 0; i < supportedFormats.size(); i++) {
            if (filePath.find(supportedFormats[i]) != string::npos) {
                return true;
            }
        }
        return false;
    }