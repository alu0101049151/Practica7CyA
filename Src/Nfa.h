/**
 * @Author Basilio Gómez Navarro
 * @date 3/11/2019
 * University of La Laguna
 * Higher School of Engineering and Technology
 * Computer Ingineering Degree
 * Grade: 2nd
 * Practice 7 - The Powerset Construction
 * Email: alu0101049151@ull.edu.es
 * Nfa.h file: Nfa class. It represents a Nondeterministic Finite Automaton.
 *             This file contains the class definition.
 * References:
 *                Practice statement:
 *                https://campusvirtual.ull.es/1920/pluginfile.php/181073/mod_assign/introattachment/0/CYA_1920_Practica_7.pdf?forcedownload=1
 * Revision history:
 *                3/11/2019 - Creation (first version) of the code
 */


#ifndef PRACTICE7_NFA_H
#define PRACTICE7_NFA_H

#include <stack>
#include <iostream>

#include "Alphabet.h"
#include "Transition.h"
#include "State.h"
#include "Dfa.h"


const char EPSILON = '~';
const std::string UNCHECKED = "@";

class Nfa {  
  public:
    Nfa(std::string& inputFile);
    Nfa(const Nfa& nfa);
    Nfa();
    ~Nfa();

    /**
    * @brief Returns the start state identifier.
    */
    std::string getStartState() const;

    /**
    * @brief Returns the set of states of the automaton.
    */
    std::set<State> getStates() const;

    /**
    * @brief Returns the set of the final states identifiers.
    */
    std::set<std::string> getFinalStates() const;

    /**
    * @brief Returns the set of chars that represents the alphabet of the
    * automaton.
    */
    Alphabet getAlphabet() const;

    /**
    * @brief Returns the vector containing all the comments read from the input file.
    */
    std::vector<std::string> getComments() const;

    /**
    * @brief Returns the set of transitions of the automaton.
    */
    std::set<Transition> getTransitions() const;

    /**
    * @brief Powerset Construction algorithm.
    * @param it is the file where the definition of the resulting DFA will be
    * saved when applying the algorithm.
    */
    void powersetConstruction(std::string& outputFile);

  protected:
    /**
    * @brief Reads the input file and builds the Nfa.
    * @param inputFile is the name of the input file.
    */
    void readAndBuildNfa(std::string& nfaDefinition);

    /**
    * @brief Carries out the epsilon-closure of a set of states.
    * @param toAnalize is the state to which the algorithm will be applied.
    */
    std::set<State> epsilonClosure(std::set<State> T);

  private:
    std::string startState_;             //!< Is the boot state.
    std::set<State> states_;             //!< Set with all the states of the Nfa.
    std::set<std::string> finalStates_;  //!< Set of id's of the final states.
    Alphabet alphabet_;                  //!< Alphabet of the Nfa.
    std::set<Transition> transitions_;   //!< Transitions of the Nfa.
    std::vector<std::string> comments_;  //!< Stores all the comments at the
                                         //!< beginning of the file.
};

#endif //PRACTICE7_NFA_H
