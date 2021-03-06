#ifndef TESTS_CPP
#define TESTS_CPP

#include "tests.hpp"

void printDescription()
{
  std::cout << "Usage: ./tests --help\n";
  std::cout << "               -h   : print this message\n";
  std::cout << "       ./tests [dir]: processes tests in target directory "
               "(default: tests_graphs or ../tests_graphs)\n\n";

  std::cout << "There are test folders, in each test folder:\n";
  std::cout << "  pattern_*.dot are learnt.\n";
  std::cout << "  test.dot is tested against learnt graphs.\n";
  std::cout << "  Once with symbols (labels) checking, once without.\n";
  std::cout << "  The number of matches is compared against those in the expected file (first with labels, second without).\n";
  std::cout << "\n";
  std::cout << "Match algorithm:\n";
  std::cout << "  Learning: via traversal tree and with a single traversal "
               "(when there is only one pattern graph).\n";
  std::cout << "  Testing: via traversal tree and with a single traversal.\n";
  std::cout << "  The result is the sum, for each node in the test graph, of "
               "the number of traversals possible from this node.\n";
  std::cout << "  Note that if two pattern graphs are identical, they will "
               "produce the same traversal and this traversal will only be "
               "counted once.\n";
  std::cout << "\n";

  std::cout << "Test 0:  [manual] small identical graphs.\n";
  std::cout << "Test 1:  [manual] small test graph with one child more (to a "
               "leaf) than pattern.\n";
  std::cout << "Test 2:  [manual] small test graph with one edge more (leaf -> "
               "leaf) than pattern.\n";
  std::cout << "Test 3:  [manual] small test graph with one child more (to a "
               "leaf) and an edge more (leaf -> root) than pattern.\n";
  std::cout << "Test 4:  [manual] same as test 3 but with different labels.\n";
  std::cout << "Test 5:  [manual] small test graph with two JCC (that have two "
               "children).\n";
  std::cout << "Test 6:  [manual] bigger test graph with 4 pattern graphs.\n";
  std::cout << "Test 7:  [manual] small graph with node repetition (INST*).\n";
  std::cout << "Test 8:  [manual] small graph with node repetition (INST*) "
               "with extraction.\n";
  std::cout << "Test 9:  [manual] generic pattern on Mirage sample.\n";
  std::cout << "Test 10: [manual] generic pattern on Mirage sample with "
               "extraction.\n";
  std::cout << "Test 11: [manual] simple loop pattern on Mirage sample.\n";
  std::cout << "Test 12: [reference to 9] same as test 9  but with PandaPE's "
               "disassembler.\n";
  std::cout << "Test 13: [reference to 10] same as test 10 but with PandaPE's "
               "disassembler.\n";
  std::cout << "Test 14: [reference to 11] same as test 11 but with PandaPE's "
               "disassembler. PandaPE does not loop rep instructions (hence 12 "
               "-> 2).\n";
  std::cout << "Test 15: [manual] non-regression test for bug in graph "
               "traversal (child number i in -k>i terms was not checked).\n";
  std::cout << "Test 16: [manual] test for lazy repeat option (zero out of "
               "three match).\n";
  std::cout << "Test 17: [manual] test for lazy repeat option (one out of "
               "three match).\n";
  std::cout << "Test 18: [reference to 0] same as test 0 but with conditions "
               "(cond=...).\n";
  std::cout << "Test 19: [reference to 13] same as test 0 but with conditions "
               "(cond=...).\n";
  std::cout << "Test 20: [manual] pattern with only one node, to test "
                "conditions on addresses.\n";
  std::cout << "Test 21: [manual] tests two patterns using conditions on the "
                "number of fathers and children of nodes.\n";
  std::cout << "Test 22: [manual] tests two patterns on the opcode field and "
               "the not operator\n";
  std::cout << "Test 23: [manual] tests regex "
               "(cond = \"inst regex '.*(x)?or.*|.*[cmp]+.*'\")\n";
  std::cout << "Test 24: [manual] arg1, arg2 test (automatically parsed)\n";
  std::cout << "Test 25: [manual] nargs, arg1, arg2 test (explicitly set)\n";
  std::cout << "Test 26: [first run] looking for xor loops in Backspace sample "
               "(md5=4ee00c46da143ba70f7e6270960823be)\n";
  std::cout << "Test 27: [reference to 26] looking for xor loops in Backspace "
                "sample using a simplified pattern with repetition on first"
                " node\n";
  std::cout << "Test 28: [manual] arg comparison within test grap (arg1 is "
                "_arg2)\n";  
  std::cout << "Test 29: [reference to 0] same as test 0 but numbered children "
               "(childnumber=1, ...).\n";
  std::cout << "Test 30: [manual] patterns with different size (tree), the "
               "second (matching) pattern is a subgraph of the first.\n";
  std::cout << "Test 31: [reference] same as test 6 with all 4 patterns in one "
               "dot file.\n";
  std::cout << "Test 32: [manual] non regression test on ghost nodes bug (fixed"
                " with switch to depth-first search.\n";
  std::cout << "Test 33: [first run] looking for basic block loops "
                "in /bin/ls sample\n";
  std::cout << "Test 34: [first run] looking for popular nodes (>=10) "
                "in /bin/ls sample)\n";
  std::cout << "Test 35: [manual] 3 invalid dot files (parsers should"
		" not crash)\n";
  std::cout << "Test 36: [reference to 35] same as test 35 with all"
		" patterns in a single file\n";
  std::cout << "Test 37: [manual] with A true, B false and C false, "
                "A and not B and C should be false\n";
  std::cout << "Test 38: [manual] with A true, B false and C false, "
                "A and (not B) and C should be false\n";
  std::cout << "Test 39: [manual] with A true, B false and C false, "
                "A and not (B) and C should be false\n";
  std::cout << "Test 40: [manual] with A true, B false and C false, "
                "A and not (B and C) should be true\n";
  std::cout << "Test 41: [manual] simple edge wildcard\n";
  std::cout << "Test 42: [manual] edge wildcard on 3 following "
                "instructions\n";
  std::cout << "Test 43: [manual] edge wildcard on loop\n";
  std::cout << "Test 44: [manual] end basic blocks test (all cases match)\n";
  std::cout << "Test 45: [manual] end basic blocks test (count)\n";
  std::cout << "Test 46: [manual] lazyrepeat option is expected to be ignored "
                "when not followed by others instructions within basic block\n";
}

#ifdef _WIN32
string Red = "";
string Green = "";
string Blue = "";
string Color_Off = "";
#else
string Red = "\x1b[1;31m";
string Green = "\x1b[1;32m";
string Blue = "\x1b[1;33m";
string Color_Off = "\x1b[0m";
#endif

bool debug = false;

#ifndef _WIN32
#ifdef SECCOMP
void drop_privileges(){
  scmp_filter_ctx ctx;
  
  // release: SCMP_ACT_KILL
  // use SCMP_ACT_TRAP or SCMP_ACT_TRACE(0) for debug
  ctx = seccomp_init(SCMP_ACT_KILL); 

  // TODO: remove the open syscall by dropping privileges at a later stage
  seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(open), 0);
  seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(openat), 0);
  seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(close), 0);
  seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(exit), 0);
  seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(exit_group), 0);
  seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(read), 0);
  seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(write), 0);
  seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(writev), 0);
  seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(munmap), 0);
  seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mmap), 0);
  seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fstat), 0);
  seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(lseek), 0);
  seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(brk), 0);
  seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(futex), 0);
  seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(ioctl), 0);
  
  int r = seccomp_load(ctx);
  RELEASE_ASSERT(r == 0);
}
#endif
#endif

int main(int argc, char *argv[]) {
  #ifndef _WIN32
  #ifdef SECCOMP
  drop_privileges();
  #endif
  #endif
  
  std::string dir_tests_base = "";

  if (argc >= 2) {
    if (strcmp(argv[1], "-h") == 0 or strcmp(argv[1], "--help") == 0) {
      printDescription();
      return 1;
    }
    dir_tests_base = string(argv[1]);
  }
  else {
    FILE *f = fopen("tests_graphs/test0/test.dot", "rb");
    if (f != NULL) {
      dir_tests_base = "tests_graphs/";
      fclose(f);
    }
    else {
      f = fopen("../tests_graphs/test0/test.dot", "rb");
      if (f != NULL) {
        dir_tests_base = "../tests_graphs/";
        fclose(f);
      }
      else {
        f = fopen("../src/tests_graphs/test0/test.dot", "rb");
        if (f != NULL) {
          dir_tests_base = "../src/tests_graphs/";
          fclose(f);
        }
        else {
          f = fopen("src/tests_graphs/test0/test.dot", "rb");
          if (f != NULL) {
            dir_tests_base = "src/tests_graphs/";
            fclose(f);
          }
        }
      }
    }
  }

  vsize_t error_number = 0;
  error_number += test_NodeInfo();

  string color;
  graph_t **grPattern = nullptr;
  graph_t *grPattern2 = nullptr;
  graph_t *grTest = nullptr;
  
  vsize_t i = 0;
  while (i < std::numeric_limits<vsize_t>::max()) {
    std::string dirPath = dir_tests_base + "/test" + std::to_string(i) + "/";
    std::string pathTest = dirPath + "test.dot";
    
    grTest = getGraphFromPath(pathTest.c_str());
    if (grTest == NULL) {
      if (i > 0) {
        std::cout << "Can't read next test.dot file, probably reached the end "
                     "of tests.\n";
      }
      else {
        std::cout << Red << "Zero (0) test done, are you sure the path is correct ?"  << Color_Off << std::endl;
        error_number++;
      }
      break;
    }

    // read expected results
    size_t expected_with_labels = 0;
    size_t expected_no_labels = 0;
    std::ifstream f_res(dirPath + "expected");

    if (f_res.good()) {
      string sLine;

      getline(f_res, sLine);
      expected_with_labels = (size_t) atoi(sLine.c_str());
      getline(f_res, sLine);
      expected_no_labels = (size_t) atoi(sLine.c_str());
    }

    f_res.close();

    cout << Blue;
    std::cout << "Running test " + std::to_string(i) + "\n";
    cout << Color_Off;
       
    if (debug){
      std::cout << "Test graph is:\n";
      graph_fprint (stdout, grTest);
    }

    vsize_t j;
    vsize_t nPattern = 0;
    for (j = 0; j < std::numeric_limits < vsize_t >::max(); j++) {
      std::string pathPattern = dirPath + "pattern_" + to_string(j) + ".dot";
      
      FILE* f = fopen(pathPattern.c_str(), "rb");
      if (f != NULL) {
	fclose(f);
      }
      else {
	break;
      }
      
      GraphList* gl = getGraphListFromPath(pathPattern.c_str());
      if (gl == NULL or gl->size == 0){
        continue; 
      }
      
      vsize_t k;
      for (k = 0; k < gl->size; k++){	
	graph_t* gr = gl->graphes[k];
        
        if (gr == NULL){
          continue;
        }
        
	grPattern = (graph_t **) realloc_or_quit(grPattern, (nPattern + 1) * sizeof(graph_t *));
        grPattern[nPattern] = gr;
        nPattern++;
      }
      freeGraphList(gl, false, false);
    }

    if (nPattern == 0){
      break;
    }

    // Match with and without labels
    error_number += test_match(grPattern, nPattern, grTest, expected_with_labels, true,
              "Checking labels", true, "tree-l-" + std::to_string(i) + ".dot");
    error_number += test_match(grPattern, nPattern, grTest, expected_no_labels, false,
              "Not checking labels", true,
              "tree-nl-" + std::to_string(i) + ".dot");

    for (j = 0; j < nPattern; j++) {
      graph_free(grPattern[j], true);
    }
    
    graph_free(grTest, true);
    
    std::cout << "\n";
    i++;
  }
  
  free(grPattern);
  
  if (error_number == 0){
    cout << Green << "All tests passed." << Color_Off << std::endl;
  }
  else {
    cout << Red << error_number << " test(s) failed." << Color_Off << std::endl;
    
  }
  
  if (error_number > 255){
    return 255; 
  }
  else {
    return (int) error_number;
  }
}

vsize_t test_NodeInfo(){
  vsize_t error_number = 0;
  
  std::cout << "Testing comparisons (NodeList)." << endl;
  NodeInfo* np = new NodeInfo();
  NodeInfo* nt = new NodeInfo();

  
  std::cout << "Testing bool_equals: ";
  CondNode* cn = new CondNode();
  cn->pattern_field = (void* NodeInfo::*) &NodeInfo::has_address;
  cn->test_field = (void* NodeInfo::*) &NodeInfo::has_address;
  cn->comparison = ComparisonFunEnum::bool_equals;
    
  np->has_address = false;
  nt->has_address = false;
  bool r = cn->evaluate(np, nt);
  error_number += print_leaf_result(r, "= ", false);
  
  np->has_address = false;
  nt->has_address = true;
  r = cn->evaluate(np, nt);
  error_number += print_leaf_result(not r, "!= ", true);
  
  CondNode::freeCondition(cn);
  
  
  std::cout << "Testing bool_test_true: ";
  cn = new CondNode();
  cn->test_field = (void* NodeInfo::*) &NodeInfo::has_address;
  cn->comparison = ComparisonFunEnum::bool_test_true;
    
  nt->has_address = true;
  r = cn->evaluate(np, nt);
  error_number += print_leaf_result(r, "= ", false);
  
  nt->has_address = false;
  r = cn->evaluate(np, nt);
  error_number += print_leaf_result(not r, "!= ", true);
  
  CondNode::freeCondition(cn);
  
  
  std::cout << "Testing str_equals: ";
  cn = new CondNode();
  cn->pattern_field = (void* NodeInfo::*) &NodeInfo::inst_str;
  cn->test_field = (void* NodeInfo::*) &NodeInfo::inst_str;
  cn->comparison = ComparisonFunEnum::str_equals;
    
  np->inst_str = "xor";
  nt->inst_str = "xor";
  r = cn->evaluate(np, nt);
  error_number += print_leaf_result(r, "= ", false);
  
  nt->inst_str = "mov";
  r = cn->evaluate(np, nt);
  error_number += print_leaf_result(not r, "!= ", true);
  
  CondNode::freeCondition(cn);
  
  
  std::cout << "Testing uint8_equals: ";
  cn = new CondNode();
  cn->pattern_field = (void* NodeInfo::*) &NodeInfo::maxChildrenNumber;
  cn->test_field = (void* NodeInfo::*) &NodeInfo::childrenNumber;
  cn->comparison = ComparisonFunEnum::uint8t_equals;
    
  np->maxChildrenNumber = 2;
  nt->childrenNumber = 2;
  r = cn->evaluate(np, nt);
  error_number += print_leaf_result(r, "= ", false);
  
  np->maxChildrenNumber = 1;
  r = cn->evaluate(np, nt);
  error_number += print_leaf_result(not r, "!= ", true);

  CondNode::freeCondition(cn);
  
  
  // Shoud return true iff pattern >= test
  std::cout << "Testing uint8_gt: ";
  cn = new CondNode();
  cn->pattern_field = (void* NodeInfo::*) &NodeInfo::maxChildrenNumber;
  cn->test_field = (void* NodeInfo::*) &NodeInfo::childrenNumber;
  cn->comparison = ComparisonFunEnum::uint8t_gt;
    
  np->maxChildrenNumber = 2;
  nt->childrenNumber = 2;
  r = cn->evaluate(np, nt);
  error_number += print_leaf_result(not r, "= ", false);
  
  np->maxChildrenNumber = 1;
  r = cn->evaluate(np, nt);
  error_number += print_leaf_result(not r, "< ", false);
  
  np->maxChildrenNumber = 3;
  r = cn->evaluate(np, nt);
  error_number += print_leaf_result(r, "> ", true);

  CondNode::freeCondition(cn);
  
  
  std::cout << "Testing vsizet_equals: ";
  cn = new CondNode();
  cn->pattern_field = (void* NodeInfo::*) &NodeInfo::address;
  cn->test_field = (void* NodeInfo::*) &NodeInfo::address;
  cn->comparison = ComparisonFunEnum::vsizet_equals;
    
  np->address = 2;
  nt->address = 2;
  r = cn->evaluate(np, nt);
  error_number += print_leaf_result(r, "= ", false);
  
  np->address = 1;
  r = cn->evaluate(np, nt);
  error_number += print_leaf_result(not r, "!= ", true);
  
  // cn evaluates to false
  std::cout << "Testing not and not not: ";
  std::list<CondNode*>* children = new std::list<CondNode*>();
  children->push_front(cn);
  cn->add_pointer_usage();
  CondNode* cn_not = new CondNode(children, UnOpEnum::logic_not);
  
  r = cn_not->evaluate(np, nt);
  error_number += print_leaf_result(r, "! ", false);
  
  CondNode* cn_not2 = new CondNode();
  cn_not2->children->push_front(cn_not);
  cn_not->add_pointer_usage();
  cn_not2->unary_operator = UnOpEnum::logic_not;
  r = cn_not2->evaluate(np, nt);
  error_number += print_leaf_result(not r, "!! ", true);
  
  
  std::cout << "Testing or on multiple operands: ";
  std::list<CondNode*>* children2 = new std::list<CondNode*>();
  children2->push_front(cn);
  cn->add_pointer_usage();
  children2->push_front(cn_not);
  cn_not->add_pointer_usage();
  
  CondNode* cn_or = new CondNode(BinOpEnum::logic_or, children2);
  r = cn_or->evaluate(np, nt);
  error_number += print_leaf_result(r, "2 ", false);
  
  cn_or->children->push_front(cn_not2);
  cn_not2->add_pointer_usage();
  r = cn_or->evaluate(np, nt);
  error_number += print_leaf_result(r, "3 ", true);
  
  
  std::cout << "Testing and on multiple operands: ";
  CondNode* cn_and = new CondNode();
  cn_and->children->push_front(cn);
  cn->add_pointer_usage();
  cn_and->children->push_front(cn_not);
  cn_not->add_pointer_usage();
  cn_and->binary_operator =  BinOpEnum::logic_and;
  r = cn_and->evaluate(np, nt);
  error_number += print_leaf_result(not r, "2 ", false);
  
  cn_and->children->push_front(cn_not2);
  cn_not2->add_pointer_usage();
  r = cn_and->evaluate(np, nt);
  error_number += print_leaf_result(not r, "3 ", true);
  
  CondNode::freeCondition(cn);
  CondNode::freeCondition(cn_not);
  CondNode::freeCondition(cn_not2);
  CondNode::freeCondition(cn_or);
  CondNode::freeCondition(cn_and);
  
  delete(np);
  delete(nt);
  
  cout << endl;
  return error_number;
}

 vsize_t test_match(graph_t **grPattern, size_t nPattern, graph_t *grTest,
               size_t expected, bool checkLabels, std::string desc,
               bool exportTree, string treePath)
{
  vsize_t error_number = 0;
  string color;
  std::cout << desc + ":\n";

  vsize_t i;
  vsize_t maxSiteSize = grPattern[0]->nodes.count;
  for (i = 1; i < nPattern; i++) {
    if (grPattern[i]->nodes.count > maxSiteSize)
      maxSiteSize = grPattern[i]->nodes.count;
  }

  ParcoursNode* tree = new ParcoursNode();

  for (i = 0; i < nPattern; i++) {
    bool added = tree->addGraphFromNode(grPattern[i], grPattern[i]->root,
                                        grPattern[i]->nodes.count, checkLabels);
    
    if (not added) {
      std::cerr << "WARNING: Pattern graph was not added to traversal tree "
             "because it already exists there or is not complete." << std::endl;
    }
  }

  if (exportTree){
    tree->saveParcoursNodeToDot(treePath);
  }
  
  printf("%d traversals reconstructed from pattern graph.\n", (int) tree->countLeaves());

  ParcoursNode::RetourParcourir ret_parcours = tree->parcourir(grTest, maxSiteSize, checkLabels, true, false);
  vsize_t count = std::get<0>(ret_parcours);
  if (count != expected) {
    color = Red;
    error_number += 1;
  }
  else {
    color = Green;
  }
  printf("%s%d traversals possible in test graph (expected: %d) with tree.%s\n", color.c_str(), (int) count, (int) expected, Color_Off.c_str());
  
  PatternsMatches* pattern_matches = std::get<1>(ret_parcours);
  freePatternsMatches(pattern_matches, true);
  tree->freeParcoursNode(); 
  
  if (nPattern == 1 and not grPattern[0]->has_wildcards) {
    Parcours *p =
        parcoursGen(grPattern[0], grPattern[0]->root->list_id, maxSiteSize);
    Parcours::RetourParcours rt =
        p->parcourir(grTest, maxSiteSize, checkLabels, true, false, false);
    vsize_t count2 = rt.first;

    if (count2 != expected) {
      color = Red;
      error_number += 1;
    }
    else {
      color = Green;
    }
    printf("%s%d traversals possible in test graph (expected: %d) with a "
           "single traversal.%s\n",
           color.c_str(), (int)count2, (int)expected, Color_Off.c_str());

    delete (rt.second);
    p->freeParcours(true);
  }
  return error_number;
}

vsize_t print_leaf_result(bool r, string desc, bool end_bool)
{
  string end_str = "";
  if (end_bool) end_str = "\n";

  if (r) {
    cout << Green << desc << Color_Off << end_str;
    return 0;
  }
  else {
    cout << Red << desc << Color_Off << end_str;
    return 1;
  }
}

#endif
