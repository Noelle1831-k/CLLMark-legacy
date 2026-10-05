def identify_data_types(self):
        '''
        Identify the data types of each attribute in the dataset.
        '''
        if not self.dataset:
            print("Dataset is empty.")
            return
        detector = DataTypeDetector()
        for column in zip(*self.dataset):
            data_type = detector.detect_type(column)
            self.data_types.append(data_type)
        self.print_data_types()