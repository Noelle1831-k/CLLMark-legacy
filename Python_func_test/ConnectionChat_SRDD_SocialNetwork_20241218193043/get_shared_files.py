def get_shared_files(self, user):
        return self.shared_files.get(user.name, [])