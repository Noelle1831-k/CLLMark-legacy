def apply_rule(self):
        # Apply the hidden rule to generate a puzzle
        if self.hidden_rule == 'addition':
            return [i + self.level for i in range(5)]
        elif self.hidden_rule == 'multiplication':
            return [i * self.level for i in range(1, 6)]
        elif self.hidden_rule == 'subtraction':
            return [i - self.level for i in range(5, 10)]