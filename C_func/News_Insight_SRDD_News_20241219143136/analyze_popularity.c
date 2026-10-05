void analyze_popularity(NewsArticle *article) {
    int popularity_score = article->view_count + (article->share_count * 2);
    article->popularity_score = popularity_score;
}