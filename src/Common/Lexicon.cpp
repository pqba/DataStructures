#include "../../include/Common/Lexicon.h"

#include <algorithm>
#include <deque>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>

// Loads entire ASCII text file into tree given a valid filename, doesn't load if invalid
void Lexicon::loadFile(const std::ifstream& textFile) {
    if (textFile.is_open()) {
        std::stringstream buffer;
        buffer << textFile.rdbuf();
        std::string corpus = buffer.str();
        loadWords(corpus);
    }
}

// Loads strings up to size  amount into ignore array
void Lexicon::loadIgnore(const int size, std::string A[]) {
    if (size <= 0) {
        ignoreLen = 0;
    } else {
        int len = size > MAX_IGNORE ? MAX_IGNORE : size;
        for (int i = 0; i < len; i++) {
            ignoredWords[i] = A[i];
        }
        ignoreLen = len;
    }
}

// Loads in space delinated newline split text to tree
void Lexicon::loadWords(const std::string& text) {
    int wc = 0;
    std::unordered_map<std::string, int> freqMap;
    std::istringstream blockStream(text);
    std::string line;

    // Other configuration options could be to change getline/lineStream to work with general chars.
    while (std::getline(blockStream, line)) {
        std::istringstream lineStream(line);
        std::string sequence;
        while (lineStream >> sequence) {
            if (freqMap.find(sequence) != freqMap.end()) {
                freqMap[sequence] += 1;
                if (wc < MAX_WC) {
                    originalStream.push_back(sequence);
                }
            } else {
                bool contains = false;
                for (int i = 0; i < ignoreLen; i++) {
                    if (ignoredWords[i] == sequence) {
                        contains = true;
                        break;
                    }
                }
                if (!contains) {
                    freqMap[sequence] = 1;
                    if (wc < MAX_WC) {
                        originalStream.push_back(sequence);
                        wc++;
                    }
                }
            }
        }
    }

    for (std::pair<std::string, int> val : freqMap) {
        textTree.insert(Word(val.first, val.second));
    }
}

// Returns textTree by a constant reference
const BinTree<Word>& Lexicon::getTree() {
    return textTree;
}

const std::vector<std::string>& Lexicon::getStream(){
    return originalStream;
}

// Finds word in textTree given w, invalid Word otherwise
BTNode<Word>* Lexicon::find(const std::string& w) {
    BTNode<Word>* nd = textTree.getRoot();
    while (nd != nullptr) {
        if (nd->val.getMsg() == w) {
            return nd;
        } else if (nd->val.getMsg() > w) {
            nd = nd->right;
        } else if (nd->val.getMsg() < w) {
            nd = nd->left;
        } else {
            return nullptr;  // Neither larger or smaller, invalid word
        }
    }
    return nullptr;
}
// removes string from tree
void Lexicon::removeWord(const std::string& w) {
    BTNode<Word>* w_search = find(w);
    if (w_search) {
        textTree.remove(w_search->val);
    }
}
// returns frequency of given string
int Lexicon::getFrequency(const std::string& w) {
    BTNode<Word>* w_search = find(w);
    if (w_search) {
        return w_search->val.freq;
    }
    return 0;
}
// Returns reference to list of highest n frequency words in tree
DoublyLinkedList<Word>* Lexicon::topWords(int n) {
    if (n <= 0 || vocabulary() <= 0) {
        return new DoublyLinkedList<Word>();
    }
    int tree_size = textTree.size();
    if (tree_size < n) {
        n = tree_size;
    }
    DoublyLinkedList<Word>* lst = textTree.inOrderList();
    std::vector<Word> wordVec;
    int l_sz = lst->size();
    wordVec.reserve(l_sz);
for (int ind = 0; ind < l_sz; ind++) {
        wordVec.push_back(lst->pop());
    }
    std::sort(wordVec.begin(), wordVec.end());

    auto* top_list = new DoublyLinkedList<Word>();
    for (int i = 0; i < n; i++) {
        top_list->add(new DLLNode<Word>(wordVec.back()));
        wordVec.pop_back();
    }
    delete lst;
    return top_list;
}

// Returns: longest word in Lexicon. "" if Lexicon empty
std::string Lexicon::longestWord() {
    int dataLen = vocabulary();
    if (vocabulary() <= 0) return "";
    Word* wordData = dllToArray(*textTree.inOrderList());

    std::string longestWord = wordData[0].getMsg();
    for (int i = 1; i < dataLen; i++) {
        std::string currWord = wordData[i].getMsg();
        if (currWord.length() > longestWord.length()) {
            longestWord = currWord;
        }
    }
    return longestWord;
}

// Returns: shortest word in Lexicon. "" if Lexicon empty
std::string Lexicon::shortestWord() {
    int dataLen = vocabulary();
    if (vocabulary() <= 0) return "";
    Word* wordData = dllToArray(*textTree.inOrderList());
    std::string shortestWord = wordData[0].getMsg();
    for (int i = 1; i < dataLen; i++) {
        std::string currWord = wordData[i].getMsg();
        if (currWord.length() < shortestWord.length()) {
            shortestWord = currWord;
        }
    }
    return shortestWord;
}

// Returns: string pair with the most similar pair (lowest Levenshtein distance). "","" if Lexicon empty
std::pair<std::string, std::string> Lexicon::mostSimilarPair() {
    if (vocabulary() <= 0) return {"", ""};
    Word* wordData = dllToArray(*textTree.inOrderList());
    int min_ld = INT_MAX;
    std::pair<std::string, std::string> sol = {"", ""};
    int N = vocabulary();
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            std::string first = wordData[i].getMsg();
            std::string second = wordData[j].getMsg();
            int ld = levenshteinDistance(first, second);
            if (ld < min_ld) {
                min_ld = ld;
                sol.first = first;
                sol.second = second;
            }
        }
    }
    return sol;
}

// Creates a Markov chain based off of textTree and frequences of words of a given order
void Lexicon::make_predictor(int order) {
    if (order < 1) {
        return;
    }
    // gather counts of each word
    chain_t m_chain;
    // Generate |integer frequencies| based on states state using full original word stream
    for (int i = 0; i < (int)originalStream.size() - order; i++) {
        // get a comma delineated string of ORDER previous items and then the next token
        std::string prev_state;
        for (int j = i; j < i + order; j++) {
            prev_state += originalStream.at(j) + std::string(",");
        }
        std::string next_token = originalStream.at(i + order);
        // check if indexing into chain/counts work and increment, if not add correspondence of m_chain[prev][next=1]
        if (m_chain.find(prev_state) != m_chain.end()) {
            std::unordered_map<std::string, float> counts = m_chain[prev_state];
            if (counts.find(next_token) != counts.end()) {
                m_chain[prev_state][next_token] += 1;
            } else {
                m_chain[prev_state][next_token] = 1;
            }
        } else {
            std::unordered_map<std::string, float> build_counts;
            build_counts[next_token] = 1;
            m_chain[prev_state] = build_counts;
        }
    }
    // Generate |float probabilities| based on prev state
    for (auto& state_maps : m_chain) {
        float total_occurences = 0;
        // count total occurences for state_maps[str key]
        for (auto& occurence_maps : state_maps.second) {
            total_occurences += occurence_maps.second;
        }
        // make probabilities state_maps[str key] / tot_occurences
        for (auto& occurence_maps : state_maps.second) {
            occurence_maps.second /= total_occurences;
        }
    }
    // create predictor
    predictor.chain = m_chain;
    predictor.order = order;
}

// Generates a text vector of [length] words using Lexicon predictor
std::vector<std::string> Lexicon::generate_text(int length) {
    if (predictor.order == 0 || length <= 0) {
        return std::vector<std::string>();
    }
    srand(time(NULL)); // non-deterministic random nums

    // Choose a random state in chain to begin with, using iterators
    int chain_size = static_cast<int>(predictor.chain.size());
    int init_index = rand() % chain_size;
    auto it = predictor.chain.begin(); 
    std::advance(it, init_index);
    std::deque<std::string> state = expand(it->first,',');
    // Add initial words to sentence
    std::vector<std::string> sentence;
    sentence.reserve(state.size());
for(std::string s : state) {
        sentence.push_back(s);
    }


    int text_size = (int)originalStream.size();
    for (int i = 0; i < length; i++) {
        std::string prediction;
        std::string prev = join(state,',');
        if(predictor.chain.find(prev) != predictor.chain.end()) {
            prediction = weightedChoice(predictor.chain[prev]);
        }
        else {
            // randomly predict a token as the given state wasn't observed
            prediction = originalStream.at(rand() % text_size);
        }
        sentence.push_back(prediction);
        // update state
        state.push_back(prediction);
        state.pop_front();
    }
    return sentence;
}
// Displays highest n frequency words in tree, seperated by a delimiter
void Lexicon::outputTopWords(int n, std::string delim) {
    if (n <= 0 || vocabulary() <= 0) {
        return;
    }
    int tree_size = textTree.size();
    n = tree_size < n ? tree_size : n;
    DoublyLinkedList<Word>* lst = textTree.inOrderList();

    std::vector<Word> wordVec;
    int l_sz = lst->size();
    for (int ind = 0; ind < l_sz; ind++) {
        wordVec.push_back(lst->pop());
    }
    std::sort(wordVec.begin(), wordVec.end(), std::greater<Word>());

    for (int i = 0; i < n; i++) {
        std::cout << wordVec.at(i).print() << delim;
    }
    std::cout << "\n";
    delete lst;
}

// Utils

// Returns array representation of doubly linked list and its length in pair object
Word* dllToArray(DoublyLinkedList<Word> dll) {
    const int sz = dll.size();  // Must be vocabulary()
    Word* result = new Word[sz];
    for (int i = 0; i < sz; i++) {
        result[i] = dll.get(i)->data;
    }
    return result;
}

// Returns an integer representing the levensthein distance between the two strings
int levenshteinDistance(const std::string& a, const std::string& b) {
    // initialize N x M array with 0's
    int N = static_cast<int>(a.length());
    int M = static_cast<int>(b.length());
    int dist[N + 1][M + 1];

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            dist[i][j] = 0;
        }
    }

    // source prefixes
    for (int i = 1; i <= N; i++) {
        dist[i][0] = i;
    }

    // targets
    for (int j = 1; j <= M; j++) {
        dist[0][j] = j;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            int substitution = (a[i - 1] == b[j - 1]) ? 0 : 1;
            dist[i][j] = std::min(std::min(dist[i - 1][j] + 1, dist[i][j - 1] + 1), dist[i - 1][j - 1] + substitution);
        }
    }
    return dist[N][M];
}

// Expands a delim seperated string and places it into a deque
std::deque<std::string> expand(const std::string& s, char delim) {
    std::stringstream wordstream(s);
    std::deque<std::string> dq;
    std::string word;
    while(std::getline(wordstream, word, delim))
    {
        dq.push_back(word);
    }
    return dq;

}
// Joins together a vector of strings using a delim character
std::string join(const std::deque<std::string>& dq, const char delim) {
    std::string combined;
    if(dq.size() == 0) {
        return std::string();
    }
    for(std::string s : dq) {
        combined += s + delim;
    }
    return combined;
}

// Returns a string from a map[str->float] where the total values in the map sum to 1.0, indiciating probabilites
std::string weightedChoice(const std::unordered_map<std::string, float>& probs) {
    float lower_bound = 0;
    srand(time(NULL)); // non-deterministic random nums
    // number between [0,1) increments of 0.001
    float choice = (rand() % 1000) / 1000;
    for (const auto& items : probs) {
        if (choice >= lower_bound && choice < items.second + lower_bound) {
            return items.first;
        }
        lower_bound += items.second;
    }
    return "";
}