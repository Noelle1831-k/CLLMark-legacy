void HarmonicLoopCreator::exportToSheetMusic(string filename) {
    SheetMusicExporter exporter;
    exporter.export(filename, sequence);
}