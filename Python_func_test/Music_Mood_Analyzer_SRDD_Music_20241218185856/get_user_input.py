def get_user_input():
    '''
    Get input from the user for audio file or URL.
    '''
    input_type = input("Enter 'file' to upload an audio file or 'url' to provide a link: ")
    if input_type.lower() == 'file':
        file_path = input("Enter the path to the audio file: ")
        return file_path
    elif input_type.lower() == 'url':
        url = input("Enter the URL of the audio track: ")
        return url
    else:
        print("Invalid input. Please enter 'file' or 'url'.")
        return get_user_input()