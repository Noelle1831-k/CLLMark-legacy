def main():
    '''
    Main function to run the Music Tempo Changer application.
    '''
    ui = UserInterface()
    args = parse_arguments()
    file_path = args.file_path
    target_tempo = args.tempo
    original_tempo = args.original_tempo
    if not validate_tempo(target_tempo):
        ui.display_message(f"Invalid tempo. Please enter a value between 50 and 200.")
        sys.exit(1)
    audio_processor = AudioProcessor()
    audio_data = audio_processor.load_audio(file_path)
    if audio_data is None:
        ui.display_message(f"Failed to load audio file.")
        sys.exit(1)
    processed_audio = audio_processor.change_tempo(audio_data, target_tempo, original_tempo)
    if processed_audio is None:
        ui.display_message(f"Failed to change tempo.")
        sys.exit(1)
    output_path = file_path.replace(f".mp3", f"_tempo_{target_tempo}.mp3")
    audio_processor.save_audio(processed_audio, output_path)
    ui.display_message(f"Tempo changed successfully. Output saved to {output_path}")