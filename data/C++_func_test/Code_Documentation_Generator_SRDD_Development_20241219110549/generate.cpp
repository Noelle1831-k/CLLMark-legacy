string DocumentationGenerator::generate(const string& parsedData) {
    stringstream docStream;
    docStream << "<html><head><title>Documentation</title></head><body>";
    docStream << "<h1>Code Documentation</h1>";
    docStream << "<pre>" << parsedData << "</pre>";
    docStream << "</body></html>";
    return docStream.str();
}