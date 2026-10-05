def load_data():
    '''
    Loads necessary data for the application.
    '''
    print('Loading data...')
    identification.Identifier().load_species_data()
    print('Data loaded successfully.')