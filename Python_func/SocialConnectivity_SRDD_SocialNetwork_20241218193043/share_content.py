def share_content(self, user, content_type, content_data):
        # Validate user
        if user not in self.users:
            raise ValueError("User does not exist.")
        # Validate content type
        if content_type not in ["article", "video", "image"]:
            raise ValueError("Unsupported content type. Supported types are: 'article', 'video', 'image'.")
        # Share content
        content = Content(user, content_type, content_data)
        self.contents.append(content)
        return content