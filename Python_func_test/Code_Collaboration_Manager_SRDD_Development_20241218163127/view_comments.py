def view_comments(self, filename):
        if filename in self.comments:
            return self.comments[filename]
        else:
            print(f"No comments for {filename}.")
            return []