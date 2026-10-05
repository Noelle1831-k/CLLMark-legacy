def check_solution(self):
        for shape in self.shapes:
            if not self.silhouette.is_shape_fit(shape):
                return False
        return True