def personalize_feed(self, summarized_news):
        personalized_feed = {}
        for category in self.user_interests:
            if category in summarized_news:
                personalized_feed[category] = summarized_news[category]
        return personalized_feed