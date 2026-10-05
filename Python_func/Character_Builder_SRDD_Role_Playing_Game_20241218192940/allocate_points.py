def allocate_points(self, points):
        for attr, value in points.items():
            if attr in self.attributes:
                self.attributes[attr] += value