def get_content_details(self):
        return {
            "content_id": self.content_id,
            "author": self.author,
            "content_type": self.content_type,
            "data": self.data,
            "likes": self.likes,
            "comments": self.comments
        }