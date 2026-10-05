def remove_tag(self, tag):
        """
        Removes a tag from the folder if it exists.
        """
        if tag in self.tags:
            self.tags.remove(tag)