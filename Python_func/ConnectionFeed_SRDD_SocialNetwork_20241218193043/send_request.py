def send_request(self, from_email, to_email):
        if to_email not in self.requests:
            self.requests[to_email] = []
        self.requests[to_email].append(from_email)
        print(f"Connection request sent from {from_email} to {to_email}.")