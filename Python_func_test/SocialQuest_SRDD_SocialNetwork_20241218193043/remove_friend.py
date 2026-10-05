def remove_friend(self, friend_username):
        if friend_username in self.friends_list:
            self.friends_list.remove(friend_username)