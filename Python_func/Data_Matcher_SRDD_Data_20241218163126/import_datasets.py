def import_datasets(self, file1, file2):
        self.dataset1 = Dataset()
        self.dataset2 = Dataset()
        self.dataset1.load_from_file(file1)
        self.dataset2.load_from_file(file2)