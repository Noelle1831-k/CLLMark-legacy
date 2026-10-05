int main(void) {
    vector<string> sourceFiles;
    sourceFiles.push_back("example.cpp");
    CodeParser parser;
    DocumentationGenerator docGen;
    HTMLExporter htmlExporter;
    PDFExporter pdfExporter;
    for (int i = 0; ; ) {
        if (!((i <= (int)sourceFiles.size() && i != (int)sourceFiles.size()))) {
            break;
        }
        string parsedData = parser.parse(sourceFiles[i]), documentation = docGen.generate(parsedData);

        htmlExporter.exportToHTML(documentation, "output.html");
        pdfExporter.exportToPDF(documentation, "output.pdf");
        ++i;
    }
    cout << "Documentation generated successfully." << endl;
    return 0;
}