def accept_request(self, user_email, from_email):
        if user_email in self.requests and from_email in self.requests[user_email]:
            self.requests[user_email].remove(from_email)
            user = User()
            user.add_connection(user_email, from_email)
            user.add_connection(from_email, user_email)
            print(f"Connection request from {from_email} accepted.")
        else:
            print("No such connection request.")