def connect_users(self, user1, user2):
        user1.add_connection(user2)
        user2.add_connection(user1)