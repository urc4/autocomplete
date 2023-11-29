filepath_sorted = "../data/american-english-dict-sorted"

with open(filepath_sorted, "r") as unsorted_dict:
    dict_text = unsorted_dict.read()
    dict_list = dict_text.split("\n")

from lev import SparseLevenshteinAutomaton


def words_within_distance(target_word, input_words, max_distance):
    lev = SparseLevenshteinAutomaton(target_word, max_distance)
    lev.build_dfa()  # Build the DFA

    result_words = []
    for word in input_words:
        current_state = lev.start()
        for c in word:
            current_state = lev.step(current_state, c)

        if lev.is_match(current_state):
            result_words.append(word)

    return result_words


# # Example usage:
# target_word = "hello"
# input_words = ["hella", "hell", "hallo", "hillo", "world", "help"]
# max_distance = 1

# result = words_within_distance(target_word, input_words, max_distance)
# print(f"Words within a distance of {max_distance} to '{target_word}': {result}")
