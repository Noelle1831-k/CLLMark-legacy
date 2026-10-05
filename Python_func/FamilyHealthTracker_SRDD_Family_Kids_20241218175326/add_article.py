def add_article(self, title, content):
        self.articles.append({"title": title, "content": content})
        print(f"Article '{title}' added successfully.")