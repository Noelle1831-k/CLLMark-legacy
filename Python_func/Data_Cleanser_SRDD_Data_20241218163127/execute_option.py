def execute_option(option, data):
    '''
    Executes the selected data cleaning operation based on user input.
    Updates the data variable with the cleaned data and logs the operation.
    '''
    if option == '1':
        data = data_cleaning.remove_duplicates(data)
        ui.display_message("Duplicates removed.")
    elif option == '2':
        data = data_cleaning.fill_missing_values(data)
        ui.display_message("Missing values filled.")
    elif option == '3':
        data = data_cleaning.standardize_data_formats(data)
        ui.display_message("Data formats standardized.")
    elif option == '4':
        ui.display_message("Exiting the application.")
        exit()
    else:
        ui.display_message("Invalid option. Please try again.")
    return data