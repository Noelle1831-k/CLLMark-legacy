def send_message(self, from_email, to_email, content):
        if to_email not in self.messages:
            self.messages[to_email] = []
        self.messages[to_email].append({'from': from_email, 'content': content})
        print(f"Message sent from {from_email} to {to_email}.")