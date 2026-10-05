def add_comment(self, filename, comment):
        if filename in self.comments:
            self.comments[filename].append(comment)
        else:
            self.comments[filename] = [comment]
        print(f"Comment added to {filename}.")