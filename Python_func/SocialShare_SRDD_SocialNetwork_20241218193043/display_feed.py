def display_feed(self):
        print(f"{self.user.username}'s Feed:")
        for content in self.database.get_content():
            if content.user in self.user.connections:
                print(content)
                print(f"Likes: {content.likes}, Comments: {len(content.comments)}")
                for comment in content.comments:
                    print(f"Comment: {comment}")