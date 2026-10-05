def __str__(self):
        return f"[{self.timestamp}] {self.project} - {self.module}: {self.message}\n{self.stack_trace}"