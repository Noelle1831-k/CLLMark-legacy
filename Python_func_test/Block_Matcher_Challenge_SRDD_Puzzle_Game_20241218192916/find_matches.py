def find_matches(self):
        matches = []
        for x in range(self.size):
            for y in range(self.size):
                if self.check_match(x, y):
                    matches.append((x, y))
        return matches