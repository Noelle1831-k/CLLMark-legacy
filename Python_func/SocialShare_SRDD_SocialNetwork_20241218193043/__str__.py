def __str__(self):
        return f"{self.user.username}'s connections: {[user.username for user in self.user.connections]}"