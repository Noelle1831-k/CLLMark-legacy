void LoopManager::exportLoop(const string& filename) {
    SF_INFO sfinfo;
    sfinfo.samplerate = 44100;  
    sfinfo.channels = 2;        
    sfinfo.format = SF_FORMAT_WAV | SF_FORMAT_PCM_16;  
    SNDFILE* outfile = sf_open(filename.c_str(), SFM_WRITE, &sfinfo);
    if (!outfile) {
        cout << "Error opening output file for export: " << sf_strerror(outfile) << endl;
        return;
    }
    short buffer[44100];  
    for (int i = 0; i < 44100; i++) {
        buffer[i] = (i % 1000) * 10;  
    }
    for (int i = 0; i < loopLength; i++) {
        sf_write_short(outfile, buffer, 44100);
    }
    cout << "Exporting loop to file: " << filename << endl;
    sf_close(outfile);
}