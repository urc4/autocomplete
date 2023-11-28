# Filepaths relative to the src directory
filepath_unsorted = "../data/american-english-dict"
filepath_sorted = "../data/american-english-dict-sorted"


def remove_accents(word):
    accent_chars = "àáâäèéêëìíîïòóôöùúûüÅ"
    unaccent_chars = "aaaaeeeeiiiioooouuuua"
    translation_table = str.maketrans(accent_chars, unaccent_chars)
    return word.translate(translation_table)


def add_accents(word):
    accent_mapping = {
        "angstrom": "Ångström",  # thre are more than 2 angsteroms
        "angstrom's": "Ångström's",
        "eclair": "éclair",
        "eclair's": "éclair's",
        "eclairs": "éclairs",
        "eclat": "éclat",
        "eclat's": "éclat's",
        "elan": "élan",
        "elan's": "élan's",
        "emigre": "émigré",
        "emigre's": "émigré's",
        "emigres": "émigrés",
        "epee": "épée",
        "epee's": "épée's",
        "epees": "épées",
        "etude": "étude",
        "etude's": "étude's",
        "etudes": "études",
    }

    return accent_mapping.get(word, word)


with open(filepath_unsorted, "r") as unsorted_dict:
    dict_text = unsorted_dict.read()
    dict_list = dict_text.split("\n")

    # Remove accents before sorting
    dict_list_no_accents = [remove_accents(word) for word in dict_list]
    dict_list_no_accents.sort(key=lambda x: x.lower())

    with open(filepath_sorted, "w") as sorted_dict:
        # Add accents back after sorting
        sorted_dict_list = [add_accents(word) for word in dict_list_no_accents]
        sorted_dict_text = "\n".join(sorted_dict_list)
        sorted_dict.write(sorted_dict_text)
