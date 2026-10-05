void Renderer::render(const Pattern& pattern, const Block blocks[]) {
    renderPattern(pattern);
    renderBlocks(blocks);
}