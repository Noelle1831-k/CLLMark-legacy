def upload_content(self, content_type, data):
        content = Content(self.username, content_type, data)
        self.content_list.append(content)
        return content