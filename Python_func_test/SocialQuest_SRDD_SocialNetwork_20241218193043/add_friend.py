def add_friend(self, friend_username):
        if friend_username not in self.friends_list:
            self.friends_list.append(friend_username)