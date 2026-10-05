def broadcast(self, message):
        if self.is_live:
            print(f"Broadcasting: {message}", flush=True)