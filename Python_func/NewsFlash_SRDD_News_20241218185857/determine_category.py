def determine_category(self, article):
        # Simple keyword-based categorization
        title = article.get("title", "").lower()
        if "politics" in title:
            return "politics"
        elif "business" in title:
            return "business"
        elif "technology" in title:
            return "technology"
        elif "sports" in title:
            return "sports"
        elif "entertainment" in title:
            return "entertainment"
        return "general"