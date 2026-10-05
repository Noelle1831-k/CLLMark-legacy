def to_dict(self):
        return {
            "name": self.name,
            "target_amount": self.target_amount,
            "reached": self.reached,
            "notified": self.notified
        }