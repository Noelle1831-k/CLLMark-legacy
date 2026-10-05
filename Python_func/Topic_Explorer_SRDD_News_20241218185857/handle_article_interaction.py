def handle_article_interaction(self, article_id):
        article_content = self.article_manager.fetch_article(article_id)
        summary = self.article_manager.summarize_article(article_content)
        metadata = self.article_manager.get_article_metadata(article_content)
        self.user_interaction.display_output(f"Summary: {summary}")
        self.user_interaction.display_output(f"Source: {metadata['source']}, Date: {metadata['date']}")
        while True:
            action = self.user_interaction.get_user_input("Choose an action: 1. Save 2. Share 3. Back")
            if action == '1':
                self.save_and_share.save_article(article_content)
            elif action == '2':
                self.save_and_share.share_article(article_content)
            elif action == '3':
                break
            else:
                self.user_interaction.display_output("Invalid choice. Please try again.")