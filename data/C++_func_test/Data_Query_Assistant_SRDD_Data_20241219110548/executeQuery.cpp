string QueryProcessor::executeQuery(Dataset& dataset) {
    return dataset.getData(parsedQuery, caseInsensitive, partialMatch);
}