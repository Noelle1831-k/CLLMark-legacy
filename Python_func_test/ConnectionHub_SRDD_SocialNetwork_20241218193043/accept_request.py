def accept_request(self, from_email, to_email):
        if from_email in self.connections and to_email in self.connections[from_email]:
            print(f"Connection request from {from_email} accepted by {to_email}.")
        else:
            print("No connection request found.")