def save_content(self, content):
        if content not in self.saved_content:
            self.saved_content.append(content)