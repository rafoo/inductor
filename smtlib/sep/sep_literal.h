/**
 * \file sep_literal.h
 * \brief SMT-LIB+SEPLOG literals.
 */

#ifndef INDUCTOR_SEP_LITERAL_H
#define INDUCTOR_SEP_LITERAL_H

#include "sep_abstract.h"
#include "sep_interfaces.h"

#include <string>

namespace smtlib {
    namespace sep {
        /* ====================================== Literal ===================================== */
        /** Literal containing a generic value */
        template<class T>
        class Literal : public virtual Node {
        public:
            T value;

        protected:
            Literal() { }
        };

        /* ================================== NumeralLiteral ================================== */
        /**
         * Numeric literal.
         * Can act as an index or a specification constant.
         */
        class NumeralLiteral : public Literal<long>,
                               public Index,
                               public SpecConstant,
                               public std::enable_shared_from_this<NumeralLiteral> {
        public:
            unsigned int base;

            inline NumeralLiteral(long value, unsigned int base)
                    : base(base) { this->value = value; }

            virtual void accept(Visitor0* visitor);

            virtual std::string toString();
        };

        /* ================================== DecimalLiteral ================================== */
        /**
         * Decimal literal.
         * Can act as a specification constant.
         */
        class DecimalLiteral : public Literal<double>,
                               public SpecConstant,
                               public std::enable_shared_from_this<DecimalLiteral> {
        public:
            inline DecimalLiteral(double value) { this->value = value; }

            virtual void accept(Visitor0* visitor);

            virtual std::string toString();
        };

        /* ================================== StringLiteral =================================== */
        /**
         * String literal.
         * Can act as a specification constant.
         */
        class StringLiteral : public Literal<std::string>,
                              public SpecConstant,
                              public std::enable_shared_from_this<StringLiteral> {
        public:
            inline StringLiteral(std::string value) { this->value = value; }

            virtual void accept(Visitor0* visitor);

            virtual std::string toString();
        };
    }
}

#endif //INDUCTOR_SEP_LITERAL_H