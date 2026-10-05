def check(self):
        return all(self.is_complete(record) for record in self.data)