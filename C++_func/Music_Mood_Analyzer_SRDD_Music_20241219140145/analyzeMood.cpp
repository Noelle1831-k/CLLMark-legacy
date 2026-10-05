void MoodAnalyzer::analyzeMood(const AudioProcessor& audioProcessor) {
    determineMood(audioProcessor.getTempo(), audioProcessor.getKey(),
                  audioProcessor.getInstrumentation(), audioProcessor.getHarmonicStructure());
}