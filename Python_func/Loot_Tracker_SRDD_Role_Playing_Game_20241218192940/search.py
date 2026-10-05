def search(self, query):
        """
        Searches for items matching the query string in their name or description.
        """
        query = query.lower()
        return [item.details() for item in self.items if query in item.name.lower() or query in item.description.lower()]