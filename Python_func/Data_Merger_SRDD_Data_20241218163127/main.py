def main():
    merger = DataMerger()
    ui = merger.user_interface
    ui.display_menu()
    file_paths = ui.get_user_input()
    datasets = [merger.import_data(path) for path in file_paths]
    merge_type = ui.get_user_input()
    merged_data = merger.merge_datasets(datasets, merge_type)
    cleaned_data = merger.handle_inconsistencies(merged_data)
    print("Merged Data:", cleaned_data)