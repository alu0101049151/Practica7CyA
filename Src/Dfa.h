/**
 * @Author Basilio Gómez Navarro
 * @date 3/11/2019
 * University of La Laguna
 * Higher School of Engineering and Technology
 * Computer Ingineering Degree
 * Grade: 2nd
 * Practice 7 - The Powerset Construction
 * Email: alu0101049151@ull.edu.es
 * Dfa.h file: Dfa class. It represents a Deterministic Finite Automaton.
 *             This file contains the class definition.
 * References:
 *                Practice statement:
 *                https://campusvirtual.ull.es/1920/pluginfile.php/181073/mod_assign/introattachment/0/CYA_1920_Practica_7.pdf?forcedownload=1
 * Revision history:
 *                3/11/2019 - Creation (first version) of the code
 */

#ifndef PRACTICE7_DFA_H
#define PRACTICE7_DFA_H

#include <vector>
#include <sstream>

#include "Alphabet.h"
#include "State.h"

const char NEWLINE = '\n';
const char SLASH = '/';
const std::string COMMENT = "// ";
const std::string ENDOFCOMMENTS = "///";
const char TAB = '\t';
const std::string S = " ";


class Dfa {
	public:
    Dfa(std::string& inputFile);
    Dfa(const Dfa& dfa);
    Dfa();
    ~Dfa();

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
    * @brief Write in the output file the description of the DFA in DOT format.
    * @param outputGv is the file where the DFA will be written in DOT format.
    */
    void drawDFA(std::string& outputGv);

	protected: 
    /**
    * @brief read the input file and builds the Dfa
    * @param inputFile is the name of the input file.
    */
    void readAndBuildDfa(std::string& dfaDefinition);

	private:
		std::string startState_;             //!< Is the boot state.
		std::set<State> states_;             //!< Set with all the states of the Dfa.
		std::set<std::string> finalStates_;  //!< Set of id's of the final states.
		Alphabet alphabet_;                  //!< Alphabet of the Dfa.
    std::set<Transition> transitions_;   //!< Transitions of the Dfa.
    std::vector<std::string> comments_;  //!< Stores all the comments at the
                                         //!< beginning of the file.
};

#endif //PRACTICE7_DFA_H

