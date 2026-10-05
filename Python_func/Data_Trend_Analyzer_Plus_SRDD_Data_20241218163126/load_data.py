def load_data():
    '''
    Load user data sets.
    '''
    importer = data_import.DataImporter()
    data = importer.import_csv('data.csv')
    return data