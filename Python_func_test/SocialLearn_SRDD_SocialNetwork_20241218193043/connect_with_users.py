def connect_with_users(self, other_user):
        if other_user not in self.connections:
            self.connections.append(other_user)
            other_user.connections.append(self)