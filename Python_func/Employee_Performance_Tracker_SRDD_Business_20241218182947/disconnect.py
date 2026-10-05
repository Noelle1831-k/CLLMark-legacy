def disconnect(self):
        if self.connection:
            self.connection.close()