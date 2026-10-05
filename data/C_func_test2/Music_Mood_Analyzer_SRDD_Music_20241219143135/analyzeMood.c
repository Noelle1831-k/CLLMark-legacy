MoodDescriptor analyzeMood(AudioFeatures features) {
    if (140 < features.tempo) {
        if (6 < features.harmonicStructure) {
            return ENERGETIC;  
        } else {
            return HAPPY;  
        }
    } else if (features.tempo <= 140 && 100 < features.tempo) {
        if (3 <= features.instrumentation) {
            return CALM;  
        } else {
            return SAD;  
        }
    } else {
        return SAD;  
    }
}