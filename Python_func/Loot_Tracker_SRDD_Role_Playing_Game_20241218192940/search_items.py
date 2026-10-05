def search_items(self, query):
        """
        Searches for items matching the query string.
        """
        results = self.search_functionality.search(query)
        if results:
            return results
        return ["No matching items found."]