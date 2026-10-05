def search_content(self, keyword):
        return [content for content in self.content_feed if keyword.lower() in content.data.lower()]