def main():
    '''
    Main function to run the Data Identifier application.
    '''
    if len(sys.argv) != 2:
        print("Usage: python main.py <dataset_file>")
        sys.exit(1)
    dataset_file = sys.argv[1]
    data_identifier = DataIdentifier()
    data_identifier.load_dataset(dataset_file)
    data_identifier.identify_data_types()