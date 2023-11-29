class SparseLevenshteinAutomaton:
    def __init__(self, string, n):
        self.string = string
        self.max_edits = n
        self.counter = [0]
        self.states = {}
        self.transitions_list = []
        self.matching_list = []

    def start(self):
        return (range(self.max_edits + 1), range(self.max_edits + 1))

    def step(self, indices_values, c):
        indices, values = indices_values
        if indices and indices[0] == 0 and values[0] < self.max_edits:
            new_indices = [0]
            new_values = [values[0] + 1]
        else:
            new_indices = []
            new_values = []

        for j, i in enumerate(indices):
            if i == len(self.string):
                break
            cost = 0 if self.string[i] == c else 1
            val = values[j] + cost
            if new_indices and new_indices[-1] == i:
                val = min(val, new_values[-1] + 1)
            if j + 1 < len(indices) and indices[j + 1] == i + 1:
                val = min(val, values[j + 1] + 1)
            if val <= self.max_edits:
                new_indices.append(i + 1)
                new_values.append(val)

        return (new_indices, new_values)

    def is_match(self, indices_values):
        indices, values = indices_values
        return bool(indices) and indices[-1] == len(self.string)

    def can_match(self, indices_values):
        indices, _ = indices_values
        return bool(indices)

    def transitions(self, indices_values):
        indices, _ = indices_values
        return set(self.string[i] for i in indices if i < len(self.string))

    def build_dfa(self):
        self.counter = [0]
        self.states = {}
        self.transitions_list = []
        self.matching_list = []
        self.explore(self.start(), self)

    def explore(self, state, lev):
        key = (
            tuple(state[0]),
            tuple(state[1]),
        )
        if key in self.states:
            return self.states[key]
        i = self.counter[0]
        self.counter[0] += 1
        self.states[key] = i
        if lev.is_match(state):
            self.matching_list.append(i)
        for c in lev.transitions(state) | set(["*"]):
            newstate = lev.step(state, c)
            j = self.explore(newstate, lev)
            self.transitions_list.append((i, j, c))
        return i


# # Example usage:
# string = "kitten"
# max_edits = 2
# lev_automaton = SparseLevenshteinAutomaton(string, max_edits)
# lev_automaton.build_dfa()

# print("Counter:", lev_automaton.counter[0])
# print("States:", lev_automaton.states)
# print("Transitions:", lev_automaton.transitions_list)
# print("Matching:", lev_automaton.matching_list)
