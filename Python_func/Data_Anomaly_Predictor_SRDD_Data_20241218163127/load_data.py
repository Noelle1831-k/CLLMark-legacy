def load_data():
    data = data_loader.load_csv('data/dataset.csv')
    preprocessed_data = data_loader.preprocess_data(data)
    return preprocessed_data