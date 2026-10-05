def bookmark_source(self, source):
        if source not in self.bookmarked_sources:
            self.bookmarked_sources.append(source)
            print(f"Source {source} bookmarked.")
        else:
            print(f"Source {source} is already bookmarked.")