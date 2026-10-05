def remove_connection(self, user_email, connection_email):
        user = User()
        if user.remove_connection(user_email, connection_email):
            user.remove_connection(connection_email, user_email)
            print(f"Connection with {connection_email} removed.")
        else:
            print("Connection not found.")