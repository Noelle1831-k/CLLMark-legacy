void visualizeData() {
        visualization.generateWordCloud(textProcessor.getWordFrequency());
        visualization.generateBarChart(textProcessor.getWordFrequency());
        visualization.generateSentimentGraph(sentimentAnalyzer.getSentimentScores());
    }