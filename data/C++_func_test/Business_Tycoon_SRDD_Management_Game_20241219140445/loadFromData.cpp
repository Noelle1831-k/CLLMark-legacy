void Business::loadFromData(std::istream &dataStream) {
    getline(dataStream, name);
    dataStream >> revenue >> expenses;
    dataStream.ignore();
}