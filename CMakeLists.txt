cmake_minimum_required(VERSION 2.8.4)
project(inductor)

set(LIB_FLEX fl)
set(LIB_CVC4 cvc4)
set(LIB_GMP gmp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wno-deprecated")

# CVC4 with `make install`
include_directories(${CMAKE_SOURCE_DIR} "smtlib" "smtlib/ast" "smtlib/sep")

# CVC4 with `make install` at a non-standard prefix
# include_directories(${CMAKE_SOURCE_DIR} "smtlib" "smtlib/ast" "smtlib/sep" "PATH-TO-CVC4-PREFIX/include")
# link_directories("PATH-TO-CVC4-PREFIX/lib")

# CVC4 without `make install`
# include_directories(${CMAKE_SOURCE_DIR} "smtlib" "smtlib/ast" "smtlib/sep" "PATH-TO-CVC4/src" "PATH-TO-CVC4/src/include" "PATH-TO-CVC4/builds/src" "PATH-TO-CVC4/builds/src/include")
# link_directories("PATH-TO-CVC4/builds/lib")

set(SOURCE_FILES
        main.cpp
        exec/execution.h
        exec/execution.cpp
        exec/execution_settings.h
        exec/execution_settings.cpp
        smtlib/parser/smtlib-glue.h
        smtlib/parser/smtlib-glue.cpp
        smtlib/parser/smtlib-bison-parser.y.h
        smtlib/parser/smtlib-bison-parser.y.c
        smtlib/parser/smtlib-flex-lexer.l.c
        smtlib/ast/ast_abstract.h
        smtlib/ast/ast_attribute.h
        smtlib/ast/ast_attribute.cpp
        smtlib/ast/ast_basic.h
        smtlib/ast/ast_basic.cpp
        smtlib/ast/ast_classes.h
        smtlib/ast/ast_command.cpp
        smtlib/ast/ast_command.h
        smtlib/ast/ast_datatype.h
        smtlib/ast/ast_datatype.cpp
        smtlib/ast/ast_fun.cpp
        smtlib/ast/ast_fun.h
        smtlib/ast/ast_identifier.cpp
        smtlib/ast/ast_identifier.h
        smtlib/ast/ast_interfaces.h
        smtlib/ast/ast_literal.cpp
        smtlib/ast/ast_literal.h
        smtlib/ast/ast_logic.cpp
        smtlib/ast/ast_logic.h
        smtlib/ast/ast_match.h
        smtlib/ast/ast_match.cpp
        smtlib/ast/ast_sort.cpp
        smtlib/ast/ast_sort.h
        smtlib/ast/ast_symbol_decl.cpp
        smtlib/ast/ast_symbol_decl.h
        smtlib/ast/ast_s_expr.cpp
        smtlib/ast/ast_s_expr.h
        smtlib/ast/ast_script.cpp
        smtlib/ast/ast_script.h
        smtlib/ast/ast_term.cpp
        smtlib/ast/ast_term.h
        smtlib/ast/ast_theory.h
        smtlib/ast/ast_theory.cpp
        smtlib/ast/ast_variable.cpp
        smtlib/ast/ast_variable.h
        smtlib/ast/visitor/ast_visitor.h
        smtlib/ast/visitor/ast_visitor.cpp
        smtlib/ast/visitor/ast_visitor_extra.h
        smtlib/ast/visitor/ast_syntax_checker.h
        smtlib/ast/visitor/ast_syntax_checker.cpp
        smtlib/ast/visitor/ast_sortedness_checker.h
        smtlib/ast/visitor/ast_sortedness_checker.cpp
        smtlib/ast/visitor/ast_term_sorter.h
        smtlib/ast/visitor/ast_term_sorter.cpp
        smtlib/ast/visitor/ast_predicate_unfolder.h
        smtlib/ast/visitor/ast_predicate_unfolder.cpp
        smtlib/ast/visitor/ast_var_renamer.h
        smtlib/ast/visitor/ast_var_renamer.cpp
        smtlib/ast/visitor/ast_duplicator.h
        smtlib/ast/visitor/ast_duplicator.cpp
        smtlib/ast/visitor/ast_term_replacer.h
        smtlib/ast/visitor/ast_term_replacer.cpp
        smtlib/ast/stack/ast_symbol_stack.h
        smtlib/ast/stack/ast_symbol_stack.cpp
        smtlib/ast/stack/ast_symbol_table.h
        smtlib/ast/stack/ast_symbol_table.cpp
        smtlib/ast/stack/ast_symbol_util.h
        smtlib/ast/stack/ast_symbol_util.cpp
        smtlib/cvc/cvc_term_translator.h
        smtlib/cvc/cvc_term_translator.cpp
        smtlib/cvc/cvc_interface.h
        smtlib/cvc/cvc_interface.cpp
        smtlib/parser/smtlib_parser.h
        smtlib/parser/smtlib_parser.cpp
        smtlib/sep/sep_abstract.h
        smtlib/sep/sep_attribute.h
        smtlib/sep/sep_attribute.cpp
        smtlib/sep/sep_basic.h
        smtlib/sep/sep_basic.cpp
        smtlib/sep/sep_classes.h
        smtlib/sep/sep_command.h
        smtlib/sep/sep_command.cpp
        smtlib/sep/sep_datatype.h
        smtlib/sep/sep_datatype.cpp
        smtlib/sep/sep_fun.h
        smtlib/sep/sep_fun.cpp
        smtlib/sep/sep_identifier.h
        smtlib/sep/sep_identifier.cpp
        smtlib/sep/sep_interfaces.h
        smtlib/sep/sep_literal.h
        smtlib/sep/sep_literal.cpp
        smtlib/sep/sep_logic.h
        smtlib/sep/sep_logic.cpp
        smtlib/sep/sep_match.h
        smtlib/sep/sep_match.cpp
        smtlib/sep/sep_script.h
        smtlib/sep/sep_script.cpp
        smtlib/sep/sep_sort.h
        smtlib/sep/sep_sort.cpp
        smtlib/sep/sep_s_expr.h
        smtlib/sep/sep_s_expr.cpp
        smtlib/sep/sep_symbol_decl.h
        smtlib/sep/sep_symbol_decl.cpp
        smtlib/sep/sep_term.h
        smtlib/sep/sep_term.cpp
        smtlib/sep/sep_theory.h
        smtlib/sep/sep_theory.cpp
        smtlib/sep/sep_variable.h
        smtlib/sep/sep_variable.cpp
        smtlib/sep/transl/sep_translator.h
        smtlib/sep/transl/sep_translator.cpp
        smtlib/sep/visitor/sep_visitor.h
        smtlib/sep/visitor/sep_visitor.cpp
        smtlib/sep/visitor/sep_visitor_extra.h
        smtlib/sep/visitor/sep_var_renamer.h
        smtlib/sep/visitor/sep_var_renamer.cpp
        smtlib/sep/visitor/sep_term_replacer.h
        smtlib/sep/visitor/sep_term_replacer.cpp
        smtlib/sep/stack/sep_symbol_table.h
        smtlib/sep/stack/sep_symbol_table.cpp
        smtlib/sep/stack/sep_symbol_util.h
        smtlib/sep/stack/sep_symbol_util.cpp
        smtlib/sep/stack/sep_symbol_stack.cpp
        smtlib/sep/stack/sep_symbol_stack.h
        smtlib/sep/visitor/sep_duplicator.h
        smtlib/sep/visitor/sep_duplicator.cpp
        smtlib/sep/visitor/sep_stack_loader.h
        smtlib/sep/visitor/sep_stack_loader.cpp
        smtlib/sep/visitor/sep_term_sorter.h
        smtlib/sep/visitor/sep_term_sorter.cpp
        smtlib/sep/visitor/sep_occ_checker.h
        smtlib/sep/visitor/sep_occ_checker.cpp
        smtlib/sep/visitor/sep_unifier.h
        smtlib/sep/visitor/sep_unifier.cpp
        pred/pred_definition.h
        pred/pred_definition.cpp
        pred/pred_table.h
        pred/pred_table.cpp
        pred/pred_analysis.h
        pred/pred_analysis.cpp
        equiv/equiv_index.h
        equiv/equiv_index.cpp
        equiv/equiv_string.h
        equiv/equiv_string.cpp
        reach/reach_index.h
        reach/reach_index.cpp
        reach/reach_string.h
        reach/reach_string.cpp
        proof/proof_state.h
        proof/proof_state.cpp
        proof/proof_tree.h
        proof/proof_tree.cpp
        proof/proof_checker.h
        proof/proof_checker.cpp
        proof/proof_build.h
        proof/proof_build.cpp
        proof/proof_rule.h
        proof/proof_rule.cpp
        proof/proof_util.h
        proof/proof_util.cpp
        strat/ast/ast_abstract.h
        strat/ast/ast_automaton.h
        strat/ast/ast_automaton.cpp
        strat/ast/ast_basic.h
        strat/ast/ast_basic.cpp
        strat/ast/ast_file.h
        strat/ast/ast_file.cpp
        strat/ast/ast_transition.h
        strat/ast/ast_transition.cpp
        strat/ast/ast_translator.h
        strat/ast/ast_translator.cpp
        strat/parser/strat-bison-parser.y.h
        strat/parser/strat-bison-parser.y.c
        strat/parser/strat-flex-lexer.l.c
        strat/parser/strat-glue.h
        strat/parser/strat-glue.cpp
        strat/parser/strat_parser.h
        strat/parser/strat_parser.cpp
        strat/proof_strategy.h
        strat/proof_strategy.cpp
        util/configuration.h
        util/configuration.cpp
        util/error_messages.h
        util/error_messages.cpp
        util/global_values.h
        util/global_values.cpp
        util/global_typedef.h
        util/logger.h
        util/logger.cpp smtlib/sep/visitor/sep_var_finder.cpp)

add_executable(inductor ${SOURCE_FILES})
target_link_libraries(inductor ${LIB_CVC4} ${LIB_GMP} ${LIB_FLEX})