def is_id_unique(self, id):
        # Check if the id is unique within the dataset
        ids = [record['id'] for record in self.data]
        return ids.count(id) == 1