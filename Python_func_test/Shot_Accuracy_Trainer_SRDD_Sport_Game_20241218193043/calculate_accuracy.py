def calculate_accuracy(self):
        accuracy = 100 - (self.distance / self.target_size) * 10
        return max(0, accuracy)