void HarmonicLoopCreator::exportToMIDI(string filename) {
    MIDIExporter exporter;
    exporter.export(filename, sequence);
}