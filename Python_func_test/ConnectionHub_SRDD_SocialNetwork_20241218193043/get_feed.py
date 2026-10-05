def get_feed(self, email):
        return self.content_feed.get(email, list())