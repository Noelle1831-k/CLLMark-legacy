def get_followers(self, user):
        return self.user_networks.get(user, [])