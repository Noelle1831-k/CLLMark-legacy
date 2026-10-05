def add_preferred_author(self, author):
        if author not in self.preferred_authors:
            self.preferred_authors.append(author)