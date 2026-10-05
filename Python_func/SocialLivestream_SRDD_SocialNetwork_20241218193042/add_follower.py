def add_follower(self, user, follower):
        if user not in self.user_networks:
            self.user_networks[user] = []
        if follower not in self.user_networks[user]:
            self.user_networks[user].append(follower)
            print(f"{follower.name} is now following {user.name}")
            # Enforce reverse follow if required
            if follower not in self.user_networks:
                self.user_networks[follower] = []
            if user not in self.user_networks[follower]:
                self.user_networks[follower].append(user)