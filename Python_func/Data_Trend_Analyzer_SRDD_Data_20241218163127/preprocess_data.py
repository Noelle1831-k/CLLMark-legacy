def preprocess_data(data):
    data.fillna(method='ffill', inplace=True)
    data.drop_duplicates(inplace=True)
    return data