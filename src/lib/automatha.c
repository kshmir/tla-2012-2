#include <stdlib.h>
#include <stdio.h>
#include "../utils/map.h"
#include "../utils/cstring.h"
#include "../utils/tree.h"
#include "automatha.h"

typedef struct state * state;
typedef struct transition * transition;

/**
 * Structure representation of the automatha.
 */
struct automatha {
	/**
	 * Map that represents all the states of the automatha.
	 */
	map states;
};

struct state {
	/**
	 * Label of the state.
	 */
	cstring label;
	/**
	 * Name of the state.
	 */
	cstring name;
	/**
	 * List of transitions of the state.
	 */
	list transitions;
	/**
	 * Tells wether a state is final or not
	 */
	int is_final;
};

struct transition {
	/**
	 * Direction of the transition.
	 */
	cstring to;
	/**
	 * Token the transition points to.
	 */
	cstring token;
};


static map _node_to_vn = NULL;

automatha automatha_init() {
	automatha a = malloc(sizeof(struct automatha));
	a->states = map_init(cstring_comparer, NULL);
	return a;
}

static transition transition_init(cstring to, cstring token) {
	transition t = malloc(sizeof(struct transition));
	t->to = cstring_copy(to);
	t->token = cstring_copy(token);
	return t;
}

static state state_init(int final, cstring name, cstring label) {
	state s = malloc(sizeof(struct state));
	s->transitions = list_init();
	s->name = cstring_copy(name);
	s->label = cstring_copy(label);
	s->is_final = final;
	return s;
}

void automatha_add_node(automatha g, int final, cstring name, cstring label) {
	state s = state_init(final, name, label);
	map_set(g->states, name, s);
}


void automatha_add_transition(automatha g, cstring from, cstring to, cstring token) {
	transition t = transition_init(to, token);
	state s = map_get(g->states, from);
	list_add(s->transitions, t);
}

static void automatha_print_states(automatha a, FILE * file) {
	list states = map_values(a->states);

	foreach(state, s, states) {
		fprintf(file, "\tnode[shape=%s] %s [label=\"%s\"]\n", (s->is_final) ? "doublecircle" : "circle", s->name, s->label);
	}

	list_free(states);
}

static void automatha_print_transitions(automatha a, FILE * file) {
	list states = map_values(a->states);

	foreach(state, s, states) {
		list transitions = s->transitions;

		foreach_(transition, t, transitions) {
			fprintf(file, "\t%s->%s [label=\"%s\"];\n", s->name, t->to, t->token);
		}

		list_free(transitions);
	}

	list_free(states);
}

void automatha_print(automatha a, FILE * file) {
	fprintf(file, "digraph {\n");

	automatha_print_states(a, file);

	automatha_print_transitions(a, file);

	fprintf(file, "}\n");
}




static cstring node_to_vn(cstring node) {


	char vn0 = 'A';
	int size = map_size(_node_to_vn);

	if (map_get(_node_to_vn, node) == NULL) {
		cstring converted = cstring_init(1);
		converted[0] = vn0 + size;

		map_set(_node_to_vn, node, converted);
	}



	return map_get(_node_to_vn, node);
}


static void store_non_terminals(grammar g, tree non_terminals) {
	list l = tree_to_list(non_terminals);

	foreach(cstring, t, l) {
		grammar_add_non_terminal(g, t);
	}
}

static void store_terminals(grammar g, tree terminals) {
	list l = tree_to_list(terminals);

	foreach(cstring, t, l) {
		grammar_add_terminal(g, t);
	}
}

grammar automatha_to_grammar(automatha a) {

	if (!_node_to_vn) {
		_node_to_vn = map_init(cstring_comparer, NULL);
	}



	grammar g = grammar_init();



	tree set_of_terminals = tree_init(cstring_comparer);
	tree set_of_non_terminals = tree_init(cstring_comparer);

	int i = 0;

	list states = map_values(a->states);


	foreach(state, s, states) {
		if (i == 0) {
			grammar_set_start_token(g, node_to_vn(s->name));
		}


		tree_add(set_of_non_terminals, node_to_vn(s->name));

		foreach_(transition, t, s->transitions) {
			cstring production = cstring_init(2);
			production[0] = t->token[0];
			production[1] = node_to_vn(t->to)[0];


			tree_add(set_of_terminals, t->token);
			tree_add(set_of_non_terminals, node_to_vn(t->to));
		}
		i++;
	}


	store_non_terminals(g, set_of_non_terminals);

	store_terminals(g, set_of_terminals);

	return g;
}


