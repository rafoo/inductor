/**
 * \file sep_visitor.h
 * \brief Abstract visitor classes the smtlib::sep hierarchy.
 */

#ifndef INDUCTOR_SEP_VISITOR_H
#define INDUCTOR_SEP_VISITOR_H

#include "sep/sep_abstract.h"
#include "sep/sep_classes.h"
#include "util/global_typedef.h"

#include <memory>
#include <vector>

namespace smtlib {
    namespace sep {
        class Visitor0 {
        protected:
            virtual void visit0(sptr_t<Node> node);
            template<class T>
            void visit0(sptr_v<T>& arr) {
                for (auto item = arr.begin(); item != arr.end(); item++) {
                    visit0(*item);
                }
            }
        public:
            virtual void visit(sptr_t<SimpleAttribute> node) = 0;
            virtual void visit(sptr_t<SExpressionAttribute> node) = 0;
            virtual void visit(sptr_t<SymbolAttribute> node) = 0;
            virtual void visit(sptr_t<BooleanAttribute> node) = 0;
            virtual void visit(sptr_t<NumeralAttribute> node) = 0;
            virtual void visit(sptr_t<DecimalAttribute> node) = 0;
            virtual void visit(sptr_t<StringAttribute> node) = 0;
            virtual void visit(sptr_t<TheoriesAttribute> node) = 0;
            virtual void visit(sptr_t<SortsAttribute> node) = 0;
            virtual void visit(sptr_t<FunsAttribute> node) = 0;

            virtual void visit(sptr_t<Symbol> node) = 0;
            virtual void visit(sptr_t<Keyword> node) = 0;
            virtual void visit(sptr_t<MetaSpecConstant> node) = 0;
            virtual void visit(sptr_t<BooleanValue> node) = 0;
            virtual void visit(sptr_t<PropLiteral> node) = 0;

            virtual void visit(sptr_t<AssertCommand> node) = 0;
            virtual void visit(sptr_t<CheckSatCommand> node) = 0;
            virtual void visit(sptr_t<CheckSatAssumCommand> node) = 0;
            virtual void visit(sptr_t<DeclareConstCommand> node) = 0;
            virtual void visit(sptr_t<DeclareDatatypeCommand> node) = 0;
            virtual void visit(sptr_t<DeclareDatatypesCommand> node) = 0;
            virtual void visit(sptr_t<DeclareFunCommand> node) = 0;
            virtual void visit(sptr_t<DeclareSortCommand> node) = 0;
            virtual void visit(sptr_t<DefineFunCommand> node) = 0;
            virtual void visit(sptr_t<DefineFunRecCommand> node) = 0;
            virtual void visit(sptr_t<DefineFunsRecCommand> node) = 0;
            virtual void visit(sptr_t<DefineSortCommand> node) = 0;
            virtual void visit(sptr_t<EchoCommand> node) = 0;
            virtual void visit(sptr_t<ExitCommand> node) = 0;
            virtual void visit(sptr_t<GetAssertsCommand> node) = 0;
            virtual void visit(sptr_t<GetAssignsCommand> node) = 0;
            virtual void visit(sptr_t<GetInfoCommand> node) = 0;
            virtual void visit(sptr_t<GetModelCommand> node) = 0;
            virtual void visit(sptr_t<GetOptionCommand> node) = 0;
            virtual void visit(sptr_t<GetProofCommand> node) = 0;
            virtual void visit(sptr_t<GetUnsatAssumsCommand> node) = 0;
            virtual void visit(sptr_t<GetUnsatCoreCommand> node) = 0;
            virtual void visit(sptr_t<GetValueCommand> node) = 0;
            virtual void visit(sptr_t<PopCommand> node) = 0;
            virtual void visit(sptr_t<PushCommand> node) = 0;
            virtual void visit(sptr_t<ResetCommand> node) = 0;
            virtual void visit(sptr_t<ResetAssertsCommand> node) = 0;
            virtual void visit(sptr_t<SetInfoCommand> node) = 0;
            virtual void visit(sptr_t<SetLogicCommand> node) = 0;
            virtual void visit(sptr_t<SetOptionCommand> node) = 0;

            virtual void visit(sptr_t<SortDeclaration> node) = 0;
            virtual void visit(sptr_t<SelectorDeclaration> node) = 0;
            virtual void visit(sptr_t<ConstructorDeclaration> node) = 0;
            virtual void visit(sptr_t<SimpleDatatypeDeclaration> node) = 0;
            virtual void visit(sptr_t<ParametricDatatypeDeclaration> node) = 0;

            virtual void visit(sptr_t<FunctionDeclaration> node) = 0;
            virtual void visit(sptr_t<FunctionDefinition> node) = 0;

            virtual void visit(sptr_t<SimpleIdentifier> node) = 0;
            virtual void visit(sptr_t<QualifiedIdentifier> node) = 0;

            virtual void visit(sptr_t<NumeralLiteral> node) = 0;
            virtual void visit(sptr_t<DecimalLiteral> node) = 0;
            virtual void visit(sptr_t<StringLiteral> node) = 0;

            virtual void visit(sptr_t<Logic> node) = 0;
            virtual void visit(sptr_t<Theory> node) = 0;
            virtual void visit(sptr_t<Script> node) = 0;

            virtual void visit(sptr_t<QualifiedConstructor> node) = 0;
            virtual void visit(sptr_t<QualifiedPattern> node) = 0;
            virtual void visit(sptr_t<MatchCase> node) = 0;

            virtual void visit(sptr_t<CompSExpression> node) = 0;

            virtual void visit(sptr_t<Sort> node) = 0;

            virtual void visit(sptr_t<SortSymbolDeclaration> node) = 0;
            virtual void visit(sptr_t<SpecConstFunDeclaration> node) = 0;
            virtual void visit(sptr_t<MetaSpecConstFunDeclaration> node) = 0;
            virtual void visit(sptr_t<SimpleFunDeclaration> node) = 0;
            virtual void visit(sptr_t<ParametricFunDeclaration> node) = 0;

            virtual void visit(sptr_t<QualifiedTerm> node) = 0;
            virtual void visit(sptr_t<LetTerm> node) = 0;
            virtual void visit(sptr_t<ForallTerm> node) = 0;
            virtual void visit(sptr_t<ExistsTerm> node) = 0;
            virtual void visit(sptr_t<MatchTerm> node) = 0;
            virtual void visit(sptr_t<AnnotatedTerm> node) = 0;

            virtual void visit(sptr_t<TrueTerm> node) = 0;
            virtual void visit(sptr_t<FalseTerm> node) = 0;
            virtual void visit(sptr_t<NotTerm> node) = 0;
            virtual void visit(sptr_t<ImpliesTerm> node) = 0;
            virtual void visit(sptr_t<AndTerm> node) = 0;
            virtual void visit(sptr_t<OrTerm> node) = 0;
            virtual void visit(sptr_t<XorTerm> node) = 0;
            virtual void visit(sptr_t<EqualsTerm> node) = 0;
            virtual void visit(sptr_t<DistinctTerm> node) = 0;
            virtual void visit(sptr_t<IteTerm> node) = 0;

            virtual void visit(sptr_t<EmpTerm> node) = 0;
            virtual void visit(sptr_t<SepTerm> node) = 0;
            virtual void visit(sptr_t<WandTerm> node) = 0;
            virtual void visit(sptr_t<PtoTerm> node) = 0;
            virtual void visit(sptr_t<NilTerm> node) = 0;

            virtual void visit(sptr_t<SortedVariable> node) = 0;
            virtual void visit(sptr_t<VariableBinding> node) = 0;
        };

        class DummyVisitor0 : public virtual Visitor0 {
        public:
            virtual void visit(sptr_t<SimpleAttribute> node);
            virtual void visit(sptr_t<SExpressionAttribute> node);
            virtual void visit(sptr_t<SymbolAttribute> node);
            virtual void visit(sptr_t<BooleanAttribute> node);
            virtual void visit(sptr_t<NumeralAttribute> node);
            virtual void visit(sptr_t<DecimalAttribute> node);
            virtual void visit(sptr_t<StringAttribute> node);
            virtual void visit(sptr_t<TheoriesAttribute> node);
            virtual void visit(sptr_t<SortsAttribute> node);
            virtual void visit(sptr_t<FunsAttribute> node);

            virtual void visit(sptr_t<Symbol> node);
            virtual void visit(sptr_t<Keyword> node);
            virtual void visit(sptr_t<MetaSpecConstant> node);
            virtual void visit(sptr_t<BooleanValue> node);
            virtual void visit(sptr_t<PropLiteral> node);

            virtual void visit(sptr_t<AssertCommand> node);
            virtual void visit(sptr_t<CheckSatCommand> node);
            virtual void visit(sptr_t<CheckSatAssumCommand> node);
            virtual void visit(sptr_t<DeclareConstCommand> node);
            virtual void visit(sptr_t<DeclareDatatypeCommand> node);
            virtual void visit(sptr_t<DeclareDatatypesCommand> node);
            virtual void visit(sptr_t<DeclareFunCommand> node);
            virtual void visit(sptr_t<DeclareSortCommand> node);
            virtual void visit(sptr_t<DefineFunCommand> node);
            virtual void visit(sptr_t<DefineFunRecCommand> node);
            virtual void visit(sptr_t<DefineFunsRecCommand> node);
            virtual void visit(sptr_t<DefineSortCommand> node);
            virtual void visit(sptr_t<EchoCommand> node);
            virtual void visit(sptr_t<ExitCommand> node);
            virtual void visit(sptr_t<GetAssertsCommand> node);
            virtual void visit(sptr_t<GetAssignsCommand> node);
            virtual void visit(sptr_t<GetInfoCommand> node);
            virtual void visit(sptr_t<GetModelCommand> node);
            virtual void visit(sptr_t<GetOptionCommand> node);
            virtual void visit(sptr_t<GetProofCommand> node);
            virtual void visit(sptr_t<GetUnsatAssumsCommand> node);
            virtual void visit(sptr_t<GetUnsatCoreCommand> node);
            virtual void visit(sptr_t<GetValueCommand> node);
            virtual void visit(sptr_t<PopCommand> node);
            virtual void visit(sptr_t<PushCommand> node);
            virtual void visit(sptr_t<ResetCommand> node);
            virtual void visit(sptr_t<ResetAssertsCommand> node);
            virtual void visit(sptr_t<SetInfoCommand> node);
            virtual void visit(sptr_t<SetLogicCommand> node);
            virtual void visit(sptr_t<SetOptionCommand> node);

            virtual void visit(sptr_t<SortDeclaration> node);
            virtual void visit(sptr_t<SelectorDeclaration> node);
            virtual void visit(sptr_t<ConstructorDeclaration> node);
            virtual void visit(sptr_t<SimpleDatatypeDeclaration> node);
            virtual void visit(sptr_t<ParametricDatatypeDeclaration> node);

            virtual void visit(sptr_t<FunctionDeclaration> node);
            virtual void visit(sptr_t<FunctionDefinition> node);

            virtual void visit(sptr_t<SimpleIdentifier> node);
            virtual void visit(sptr_t<QualifiedIdentifier> node);

            virtual void visit(sptr_t<NumeralLiteral> node);
            virtual void visit(sptr_t<DecimalLiteral> node);
            virtual void visit(sptr_t<StringLiteral> node);

            virtual void visit(sptr_t<Logic> node);
            virtual void visit(sptr_t<Theory> node);
            virtual void visit(sptr_t<Script> node);

            virtual void visit(sptr_t<QualifiedConstructor> node);
            virtual void visit(sptr_t<QualifiedPattern> node);
            virtual void visit(sptr_t<MatchCase> node);

            virtual void visit(sptr_t<CompSExpression> node);

            virtual void visit(sptr_t<Sort> node);

            virtual void visit(sptr_t<SortSymbolDeclaration> node);
            virtual void visit(sptr_t<SpecConstFunDeclaration> node);
            virtual void visit(sptr_t<MetaSpecConstFunDeclaration> node);
            virtual void visit(sptr_t<SimpleFunDeclaration> node);
            virtual void visit(sptr_t<ParametricFunDeclaration> node);

            virtual void visit(sptr_t<QualifiedTerm> node);
            virtual void visit(sptr_t<LetTerm> node);
            virtual void visit(sptr_t<ForallTerm> node);
            virtual void visit(sptr_t<ExistsTerm> node);
            virtual void visit(sptr_t<MatchTerm> node);
            virtual void visit(sptr_t<AnnotatedTerm> node);

            virtual void visit(sptr_t<TrueTerm> node);
            virtual void visit(sptr_t<FalseTerm> node);
            virtual void visit(sptr_t<NotTerm> node);
            virtual void visit(sptr_t<ImpliesTerm> node);
            virtual void visit(sptr_t<AndTerm> node);
            virtual void visit(sptr_t<OrTerm> node);
            virtual void visit(sptr_t<XorTerm> node);
            virtual void visit(sptr_t<EqualsTerm> node);
            virtual void visit(sptr_t<DistinctTerm> node);
            virtual void visit(sptr_t<IteTerm> node);

            virtual void visit(sptr_t<EmpTerm> node);
            virtual void visit(sptr_t<SepTerm> node);
            virtual void visit(sptr_t<WandTerm> node);
            virtual void visit(sptr_t<PtoTerm> node);
            virtual void visit(sptr_t<NilTerm> node);

            virtual void visit(sptr_t<SortedVariable> node);
            virtual void visit(sptr_t<VariableBinding> node);
        };
    }
}

#endif //INDUCTOR_SEP_VISITOR_H