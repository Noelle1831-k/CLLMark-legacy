def start_stream(self, title):
        self.title = title
        self.is_live = True
        print(f"{self.user.name} has started a livestream: {self.title}")