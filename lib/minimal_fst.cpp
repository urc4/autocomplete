#include "state.h"
#include "minimal_fst.h"

std::string InexistentFileException::what() {
    return "Unable to open file";
}

minimal_fst::minimal_fst(std::string filename) {
    std::ifstream file(filename);
        if (!file) {
            throw InexistentFileException();
        }

    //parameters from the pseudocode
    dictionary dict;
    std::vector<state*> temp_state;
    temp_state.reserve(MAX_WORD_SIZE + 1);
    std::string curr_word, word_suffix, common_prefix, temp_string;
    std::string prev_word = "";
    std::set<std::string> temp_set;
    int i, j, prefix_length;
    //todo: implement int curr_output;
    //todo: implement int c;

    //other parameters
    int curr_word_index = 0;

    //pseudocode
    for(i = 0; i <= MAX_WORD_SIZE; i++) {
        temp_state[i] = new state();
    }

    while(std::getline(file, curr_word)) {
        i = 0;
        curr_word_index++;
        while(i < curr_word.length() && i < prev_word.length() && prev_word[i] == curr_word[i]) {
            i++;
        }
        prefix_length = i;

        for(i = prev_word.length() - 1; i >= prefix_length; i--) {
            temp_state[i]->set_transition(prev_word[i], dict.find_minimized(temp_state[i+1], count, size));
        }

        for(i = prefix_length; i <= curr_word.length()-1; i++) {
            temp_state[i+1]->clear();
            temp_state[i]->set_transition(curr_word[i], temp_state[i+1]);
        }

        if(curr_word != prev_word) {
            temp_state[curr_word.length()]->set_final(true);
        }
        prev_word = curr_word;
    }

    for(i = curr_word.length()-1; i >= 0; i--) {
        temp_state[i]->set_transition(prev_word[i], dict.find_minimized(temp_state[i+1], count, size));
    }

    root = dict.find_minimized(temp_state[0], count, size);
}

int minimal_fst::count_vertices() {
    return count;
}

int minimal_fst::get_size() {
    return size;
}

void minimal_fst::display(std::string prefix, int n) {
    state *s = root;
    int i = 0;
    std::vector<std::string> output;
    std::cout << "------------------------\n";
    for(auto c : prefix) {
        s = s->get_transition(c);
        if(s == nullptr) {
            std::cout << "Nao foram encontrados resultados\n";
            for(; i < n-1; i++) {
                std::cout << "\033[2K\n";
            }
            return;
        }
    }
    int n_words = s->dfs(output, prefix, n);
    for(auto word : output) {
        std::cout << "\033[2K\033[0G" << word << "\n";
        i++;
    }
    for(; i < n; i++) {
        std::cout << "\033[2K\n";
    }
}
//a