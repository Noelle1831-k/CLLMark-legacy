def __init__(self):
        self.trending = TrendingTopics()
        self.search = SearchNews()
        self.article_manager = ArticleManager()
        self.user_interaction = UserInteraction()
        self.save_and_share = SaveAndShare()