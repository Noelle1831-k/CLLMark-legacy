def remove_follower(self, user, follower):
        if user in self.user_networks and follower in self.user_networks[user]:
            self.user_networks[user].remove(follower)
            print(f"{follower.name} has unfollowed {user.name}")