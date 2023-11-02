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
    std::size_t i, j, prefix_length_plus1;
    //todo: implement int curr_output;
    //todo: implement int c;

    //other parameters
    int curr_word_index = 0;

    //pseudocode
    for(i = 0; i <= MAX_WORD_SIZE; i++) {
        temp_state[i] = new state();
    }

    while(std::getline(file, curr_word)) {
        i = 1;
        curr_word_index++;
        while(i < curr_word.length() && i < prev_word.length() && prev_word[i] == curr_word[i]) {
            i++;
        }
        prefix_length_plus1 = i;

        for(i = prev_word.length(); i >= prefix_length_plus1; i--) {
            temp_state[i-1]->set_transition(curr_word[i], dict.find_minimized(temp_state[i]));
        }

        for(i = prefix_length_plus1; i <= curr_word.length(); i++) {
            temp_state[i]->clear();
            temp_state[i-1]->set_transition(curr_word[i], temp_state[i]);
        }

        if(curr_word != prev_word) {
            temp_state[curr_word.length()]->set_final(true);
            //todo implement output
        }

        for(j = 1; j <= prefix_length_plus1-1; j++) {
            //todo implement output
        }
    }

    for(i = curr_word.length(); i >= 1; i--) {
        temp_state[i-1]->set_transition(prev_word[i], dict.find_minimized(temp_state[i]));
    }

    root = dict.find_minimized(temp_state[0]);
}