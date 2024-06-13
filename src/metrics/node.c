#include "node.h"
#include "../metrics.h"

double SGA_degree_of_node(StreamGraph* sg, size_t node_id) {
	size_t sum = 0;
	TemporalNode node = sg->nodes.nodes[node_id];
	for (size_t i = 0; i < node.nb_neighbours; i++) {
		sum += SGA_IntervalsSet_size(sg->links.links[node.neighbours[i]].presence);
	}
	return (double)sum / (double)SGA_size_of_lifespan(sg);
}

double SGA_contribution_of_node(StreamGraph* sg, size_t node_id) {
	size_t size = SGA_IntervalsSet_size(sg->nodes.nodes[node_id].presence);
	return (double)size / (double)SGA_size_of_lifespan(sg);
}