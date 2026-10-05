int main() {
    vector<string> sourceFiles;
    sourceFiles.push_back("example.cpp");
    CodeParser parser;
    DocumentationGenerator docGen;
    HTMLExporter htmlExporter;
    PDFExporter pdfExporter;
    for (int i = 0; i < (int)sourceFiles.size(); i++) {
        string parsedData = parser.parse(sourceFiles[i]);
        string documentation = docGen.generate(parsedData);
        htmlExporter.exportToHTML(documentation, "output.html");
        pdfExporter.exportToPDF(documentation, "output.pdf");
    }
    cout << "Documentation generated successfully." << endl;
    return 0;
}