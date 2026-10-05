def main():
    # Initialize DataMatcher
    matcher = DataMatcher()
    # Import datasets
    dataset1_path = 'dataset1.csv'
    dataset2_path = 'dataset2.csv'
    matcher.import_datasets(dataset1_path, dataset2_path)
    # Specify fields to match
    fields_to_match = ['field1', 'field2']
    matcher.specify_fields(fields_to_match)
    # Match data
    matcher.match_data()
    # Provide summary of matched records
    matcher.summary()
    # Export matched records
    output_file = 'matched_records.csv'
    matcher.export_matched_records(output_file)