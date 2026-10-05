def display_headlines(self, articles):
        # Display headlines to the user
        for idx, article in enumerate(articles):
            print(f"{idx + 1}. {article['title']}")