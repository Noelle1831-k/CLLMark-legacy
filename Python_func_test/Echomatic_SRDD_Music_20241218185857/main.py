def main():
    if len(sys.argv) != 4:
        print("Usage: python echomatic.py <input_file> <output_file> <delay>")
        sys.exit(1)
    input_file = sys.argv[1]
    output_file = sys.argv[2]
    delay = float(sys.argv[3])
    # Validate input file path
    validate_file_path(input_file)
    # Ensure the output directory exists
    ensure_directory_exists(output_file)
    # Process the audio file
    track, sample_rate = read_audio(input_file)
    processed_track = apply_echo(track, delay, 0.5)
    write_audio(output_file, processed_track, sample_rate)