#!/usr/bin/env python
import argparse
from pygrap import *


def parse_arguments():
    """
    Parse the arguments of the program.
    """
    parser = argparse.ArgumentParser()
    group = parser.add_mutually_exclusive_group()

    # Arguments
    group.add_argument("-v", "--verbosity", action="count", default=0,
                       help="increase output verbosity")
    group.add_argument("-q", "--quiet", action="store_true", default=False)
    parser.add_argument("-ncl", "--nochecklabels", action="store_false", default=True,
                        help="do not check the labels of sites")
    parser.add_argument("patternFile", help="The pattern to search")
    parser.add_argument("testFile", nargs='+', help="The file in which we will lookfor the pattern")

    return parser.parse_args()


def main():
    """
    Main
    """
    args = parse_arguments()

    if args.verbosity >= 1:
        print("Parsing pattern file.")

    pattern_graph = getGraphFromFile(args.patternFile)
    n_pattern = pattern_graph.nodes.size

    if args.verbosity >= 1:
        print("Done.")

    parcours = parcoursLargeur(pattern_graph, pattern_graph.root.list_id,
                               n_pattern)
    if args.verbosity >= 2:
        print("Pattern Parcours is:\n" + parcours.toString() + "\n")
    
    if not args.quiet:
        print("Pattern graph (%s) has %d nodes." % (args.patternFile, n_pattern))

    for test_path in args.testFile:
        if args.verbosity >= 1:
            print("Parsing test file.")

        test_graph = getGraphFromFile(test_path)
        n_test = test_graph.nodes.size

        if args.verbosity >= 1:
            print("Done.")

        rt = parcours.parcourir(test_graph, n_pattern, args.nochecklabels, True, not args.quiet, False)
        count = rt.first

        if not args.quiet:
            print("\nTest graph (%s) has %d nodes." % (test_path, n_test))
            print("%d traversal(s) possible in %s." % (count, test_path))
        elif count >= 1:
            print("%s %d" % (test_path, count))

        list_gotten = rt.second

        if not list_gotten.empty():
            print("\nExtracted nodes:")

            # For each match
            for f_index, found_nodes in enumerate(list_gotten, start=1):
                print("Match %d" % f_index)

                for getid, node_list in found_nodes.iteritems():
                    if not node_list.empty():
                        for n_index, node in enumerate(node_list):
                            s = str(getid)

                            if node_list.size() > 1:
                                s += str(n_index)

                            s += ": "

                            if node.info.has_address:
                                s += hex(node.info.address) + ", "

                            s += node.info.inst_str
                            print s

                freeMapGotten(found_nodes)
        del(list_gotten)
        graph_free(test_graph, True)
    graph_free(pattern_graph, True)

if __name__ == '__main__':
    main()