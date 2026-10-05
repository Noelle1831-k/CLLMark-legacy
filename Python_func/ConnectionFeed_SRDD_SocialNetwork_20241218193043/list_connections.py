def list_connections(self, user_email):
        user = User()
        connections = user.get_connections(user_email)
        if connections:
            print(f"Connections for {user_email}: {connections}")
        else:
            print("No connections found.")