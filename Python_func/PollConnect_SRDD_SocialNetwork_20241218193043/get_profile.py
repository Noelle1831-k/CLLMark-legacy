def get_profile(self):
        return self.db.load_users().get(self.name, None)