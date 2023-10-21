# filepath relative to the src directory
filepath_unsorted = "../data/american-english-dict"
filepath_sorted = "../data/american-english-dict-sorted"

with open(filepath_unsorted, "r") as unsorted_dict:
    dict_text = unsorted_dict.read()
    dict_list = dict_text.split("\n")

    with open(filepath_sorted, "w") as sorted_dict:
        dict_list.sort()
        sorted_dict_text = "\n".join(dict_list)
        sorted_dict.write(sorted_dict_text)
