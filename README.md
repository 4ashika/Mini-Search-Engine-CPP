# Mini-Search-Engine-CPP

A terminal-based search engine implemented in C++17. It utilizes an **Inverted Index** and a **Trie** data structure to provide ranked search results and real-time query suggestions.

## Key Features
- **Ranked Retrieval:** Implements **TF-IDF** (Term Frequency-Inverse Document Frequency) to rank documents by relevance.
- **Boolean Query Support:** Search using multiple keywords with implicit `AND` logic.
- **Instant Autocomplete:** A custom-built **Trie** (Prefix Tree) provides $O(L)$ query suggestions.
- **Diagnostic Commands:** Support for `/df` (Document Frequency) and `/tf` (Term Frequency) diagnostics.

## Data Structures & Complexity
- **Inverted Index:** `std::unordered_map<string, PostingList>` providing $O(1)$ lookup.
- **Prefix Tree (Trie):** Used for vocabulary storage and autocomplete suggestions.
- **Complexity:**
  - **Indexing:** $O(N)$ (where N is total words).
  - **Search:** $O(K)$ (where K is number of query terms).
  - **Autocomplete:** $O(L)$ (where L is prefix length).

## Usage
1. **Compile:** `make`
2. **Run:** `./search_engine`
3. **Commands:**
   - `/search <query>` : Ranked search for keywords.
   - `/df <word>` : Get document frequency of a word.
   - `/tf <docID> <word>` : Get term frequency of a word in a specific document.
   - `/suggest <prefix>` : Get autocomplete suggestions.
