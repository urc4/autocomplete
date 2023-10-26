import tkinter as tk

window = tk.Tk()
window.title("Autocomplete")

window.rowconfigure(0, minsize=800, weight=1)
window.columnconfigure(1, minsize=800, weight=1)


frm_buttons = tk.Frame(
    master=window,
    relief=tk.RAISED,
    bd=2,
)
btn_fst = tk.Button(
    master=frm_buttons,
    text="FST",
)
btn_levesthein = tk.Button(
    master=frm_buttons,
    text="Levesthein",
)
btn_trie = tk.Button(master=frm_buttons, text="Trie")

frm_words = tk.Frame(master=window)
ent_word = tk.Entry(
    master=frm_words,
    bg="red",
)
lbl_results = tk.Text(
    master=frm_words,
    bg="blue",
)

btn_fst.grid(
    row=0,
    column=0,
    sticky="ew",
    padx=5,
    pady=5,
)
btn_levesthein.grid(
    row=1,
    column=0,
    sticky="ew",
    padx=5,
    pady=5,
)

btn_trie.grid(row=2, column=0, sticky="ew", padx=5, pady=5)

ent_word.grid(
    row=0,
    column=0,
    sticky="ew",
)
lbl_results.grid(
    row=1,
    column=0,
    sticky="nsew",
)

frm_buttons.grid(
    row=0,
    column=0,
    sticky="ns",
)
frm_words.grid(
    row=0,
    column=1,
    sticky="nsew",
)

frm_words.rowconfigure(
    0,
    minsize=50,
    weight=0,
)
frm_words.rowconfigure(
    1,
    minsize=800,
    weight=1,
)

frm_words.columnconfigure(
    0,
    minsize=800,
    weight=1,
)

window.mainloop()
