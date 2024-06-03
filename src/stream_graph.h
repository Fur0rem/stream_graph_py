#ifndef STREAM_GRAPH_H
#define STREAM_GRAPH_H

#include "interval.h"
#include "utils.h"

// Node in a graph
typedef struct {
    IntervalVector present_at;
    const char* label;
} TemporalNode;
DefVector(TemporalNode);

// Undirected link
typedef struct {
    IntervalVector present_at;
    size_t nodes[2];
    //Time weight;
} Link;
DefVector(Link);

typedef struct {
    Interval time;
    TemporalNodeVector temporal_nodes;
    LinkVector links;
} StreamGraph;

bool is_node_present_at(TemporalNode node, Time time);
bool is_link_present_at(Link link, Time time);
bool are_nodes_linked_at(StreamGraph* graph, size_t node1, size_t node2, Time time);

StreamGraph* stream_graph_from(Interval time, TemporalNodeVector nodes, LinkVector links);

#endif // STREAM_GRAPH_H