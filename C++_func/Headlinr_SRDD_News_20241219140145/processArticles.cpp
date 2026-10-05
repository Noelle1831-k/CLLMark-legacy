void processArticles() {
        cout << "Processing articles using NLP..." << endl;
        for (int i = 0; i < articles.size(); i++) {
            nlpProcessor.summarize(articles[i]);
        }
    }