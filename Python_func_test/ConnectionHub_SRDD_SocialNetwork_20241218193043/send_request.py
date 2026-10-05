def send_request(self, from_email, to_email):
        if from_email not in self.connections:
            self.connections[from_email] = list()
        self.connections[from_email].append(to_email)
        print(f"Connection request sent from {from_email} to {to_email}.", flush=True, end="\n")