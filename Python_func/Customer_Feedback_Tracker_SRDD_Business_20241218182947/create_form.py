def create_form():
    '''
    Create a new feedback form.
    '''
    print("Creating a new feedback form...")
    form = {}
    form['title'] = input("Enter form title: ")
    form['description'] = input("Enter form description: ")
    form['questions'] = []
    while True:
        question = input("Enter a question (or type 'done' to finish): ")
        if question.lower() == 'done':
            break
        form['questions'].append(question)
    with open('forms.json', 'a') as f:
        json.dump(form, f)
        f.write('\n')
    print("Feedback form created successfully.")