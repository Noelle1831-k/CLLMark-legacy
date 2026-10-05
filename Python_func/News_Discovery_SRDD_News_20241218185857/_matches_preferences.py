def _matches_preferences(self, article):
        '''
        Checks if an article matches the user's preferences.
        '''
        category_match = not self.preferences["categories"] or article.get("category") in self.preferences["categories"]
        source_match = not self.preferences["sources"] or article.get("source") in self.preferences["sources"]
        return category_match and source_match