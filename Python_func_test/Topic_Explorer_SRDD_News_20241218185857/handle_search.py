def handle_search(self):
        topic = self.user_interaction.get_user_input("Enter topic to search:")
        self.search.search_topic(topic)
        while True:
            article_choice = self.user_interaction.get_user_input("Enter article number to view details or 'b' to go back:")
            if article_choice.lower() == 'b':
                break
            elif article_choice.isdigit():
                article_id = int(article_choice)
                self.handle_article_interaction(article_id)
            else:
                self.user_interaction.display_output("Invalid choice. Please try again.")