def parse_arguments():
    '''
    Parses command-line arguments for file paths and tempo settings.
    '''
    parser = argparse.ArgumentParser(description='Music Tempo Changer')
    parser.add_argument('file_path', type=str, help='Path to the input audio file')
    parser.add_argument('tempo', type=int, help='Desired tempo for the audio file')
    return parser.parse_args()