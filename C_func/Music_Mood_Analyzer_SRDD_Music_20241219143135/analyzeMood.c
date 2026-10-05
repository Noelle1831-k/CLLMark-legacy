MoodDescriptor analyzeMood(AudioFeatures features) {
    if (features.tempo > 140) {
        if (features.harmonicStructure > 6) {
            return ENERGETIC;  
        } else {
            return HAPPY;  
        }
    } else if (features.tempo <= 140 && features.tempo > 100) {
        if (features.instrumentation >= 3) {
            return CALM;  
        } else {
            return SAD;  
        }
    } else {
        return SAD;  
    }
}