def add_tag(self, tag):
        """
        Adds a tag to the folder if it's not already present.
        """
        if tag not in self.tags:
            self.tags.append(tag)