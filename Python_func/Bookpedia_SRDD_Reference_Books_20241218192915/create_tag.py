def create_tag(self, tag):
        for book in self.books:
            if tag not in book.tags:
                book.tags.append(tag)