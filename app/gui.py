import tkinter as tk

ALGORITHM = None


def on_fst_click():
    btn_fst.config(bg="green")
    btn_levesthein.config(bg=original_bg_color)
    btn_trie.config(bg=original_bg_color)
    global ALGORITHM
    ALGORITHM = "FST"


def on_levesthein_click():
    btn_fst.config(bg=original_bg_color)
    btn_levesthein.config(bg="green")
    btn_trie.config(bg=original_bg_color)
    global ALGORITHM
    ALGORITHM = "LEV"


def on_trie_click():
    btn_fst.config(bg=original_bg_color)
    btn_levesthein.config(bg=original_bg_color)
    btn_trie.config(bg="green")
    global ALGORITHM
    ALGORITHM = "TRIE"


def on_key(event):
    if ALGORITHM == "FST":
        print("Key event for FST")
    elif ALGORITHM == "LEV":
        print("Key event for Levesthein")
    elif ALGORITHM == "TRIE":
        print("Key event for Trie")

    text_entered = ent_word.get()
    lbl_results.config(state=tk.NORMAL)
    lbl_results.delete(1.0, tk.END)
    lbl_results.insert(tk.END, text_entered)
    lbl_results.config(state=tk.DISABLED)


window = tk.Tk()
window.title("Autocomplete")

window.rowconfigure(0, minsize=800, weight=1)
window.columnconfigure(1, minsize=800, weight=1)

original_bg_color = "black"

frm_buttons = tk.Frame(master=window, relief=tk.RAISED, bd=2)
btn_fst = tk.Button(
    master=frm_buttons,
    text="FST",
    command=on_fst_click,
    bg=original_bg_color,
    fg="white",
)

btn_levesthein = tk.Button(
    master=frm_buttons,
    text="Levesthein",
    command=on_levesthein_click,
    bg=original_bg_color,
    fg="white",
)
btn_trie = tk.Button(
    master=frm_buttons,
    text="Trie",
    command=on_trie_click,
    bg=original_bg_color,
    fg="white",
)


frm_words = tk.Frame(master=window)
ent_word = tk.Entry(master=frm_words, insertbackground="white", bg="black", fg="white")
lbl_results = tk.Text(master=frm_words, state=tk.DISABLED, bg="black", fg="white")

btn_fst.grid(row=0, column=0, sticky="ew", padx=5, pady=5)
btn_levesthein.grid(row=1, column=0, sticky="ew", padx=5, pady=5)

btn_trie.grid(row=2, column=0, sticky="ew", padx=5, pady=5)

ent_word.grid(row=0, column=0, sticky="ew")
lbl_results.grid(row=1, column=0, sticky="nsew")

frm_buttons.grid(row=0, column=0, sticky="ns")
frm_words.grid(row=0, column=1, sticky="nsew")

frm_words.rowconfigure(0, minsize=50, weight=0)
frm_words.rowconfigure(1, minsize=800, weight=1)

frm_words.columnconfigure(0, minsize=800, weight=1)


on_fst_click()
ent_word.bind("<Key>", on_key)
window.mainloop()
