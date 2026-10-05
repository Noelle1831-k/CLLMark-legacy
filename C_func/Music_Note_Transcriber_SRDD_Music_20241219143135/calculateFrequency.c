double calculateFrequency(double sample) {
    return 440.0 * pow(2.0, (sample - 69.0) / 12.0); 
}