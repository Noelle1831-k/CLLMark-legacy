def manage_forms():
    '''
    Manage existing feedback forms.
    '''
    print("Managing feedback forms...")
    try:
        with open('forms.json', 'r') as f:
            forms = f.readlines()
            for index, form in enumerate(forms):
                print(f"Form {index + 1}: {form}")
    except FileNotFoundError:
        print("No forms found. Please create a form first.")