/**
 * \file execution.h
 * \brief Execution handling.
 */

#ifndef INDUCTOR_EXECUTION_H
#define INDUCTOR_EXECUTION_H

#include "execution_settings.h"

#include "parser/smtlib_parser.h"
#include "util/global_typedef.h"

#include <memory>

namespace inductor {
    /** Class handling the execution of the project */
    class Execution {
    private:
        sptr_t<ExecutionSettings> settings;
        sptr_t<smtlib::ast::Node> ast;

        bool parseAttempted, parseSuccessful;
        bool syntaxCheckAttempted, syntaxCheckSuccessful;
        bool sortednessCheckAttempted, sortednessCheckSuccessful;

    public:
        /** Execution instance with default settings */
        Execution();

        /** Execution instance with specific settings */
        Execution(sptr_t<ExecutionSettings> settings);

        /** Parse an input file */
        bool parse();

        /** Check the syntax of an input file */
        bool checkSyntax();

        /** Check the sortedness of an input file */
        bool checkSortedness();

        /** Unfold the inductive predicates defined in an input file */
        bool unfoldPredicates();

        /** Check entailment(s) specified in an input file */
        bool checkEntailment();

        /** Run the input file in CVC4 */
        bool run();
    };
}

#endif //INDUCTOR_EXECUTION_H
