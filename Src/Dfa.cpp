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

#include "Dfa.h"

Dfa::Dfa(std::string& inputFile) {
  readAndBuildDfa(inputFile);
}

Dfa::Dfa(const Dfa& dfa):
  startState_(dfa.startState_),
  states_(dfa.states_),
  finalStates_(dfa.finalStates_),
  alphabet_(dfa.alphabet_),
  comments_(dfa.comments_) {}

Dfa::Dfa() {}

Dfa::~Dfa() {}


/**
* @brief Returns the start state identifier.
*/
std::string Dfa::getStartState() const {
  return startState_;
}


/**
* @brief Returns the set of states of the automaton.
*/
std::set<State> Dfa::getStates() const {
  return states_;
}


/**
* @brief Returns the set of the final states identifiers.
*/
std::set<std::string> Dfa::getFinalStates() const {
  return finalStates_;
}


/**
* @brief Returns the set of chars that represents the alphabet of the
* automaton.
*/
Alphabet Dfa::getAlphabet() const {
  return alphabet_;
}


/**
* @brief Returns the vector containing all the comments read from the input file.
*/
std::vector<std::string> Dfa::getComments() const {
  return comments_;
}


/**
* @brief Returns the set of transitions of the automaton.
*/
std::set<Transition> Dfa::getTransitions() const {
  return transitions_;
}


/**
* Reads the input file with the Dfa definition and build the automaton 
* from the read data
*/
void Dfa::readAndBuildDfa(std::string& dfaDefinition) {
  std::ifstream inputFile;
  inputFile.open(dfaDefinition);

  if (!inputFile.is_open()) {
    std::cerr << "There was a problem opening the inputfile, ";
    std::cerr << "please, try again." << NEWLINE;
  }
  else {
   std::string readed;      //!< Stores what is read every time we read a line from the file

   std::getline(inputFile, readed);
   std::cout << "Readed: " << readed << NEWLINE;
   std::string auxStr = readed.substr (0,3);
   
   bool isComment = auxStr == COMMENT;
   bool noEndComment = auxStr != ENDOFCOMMENTS; // ENDOFCOMMENTS = "///" means the end of comments
  
  //================================================
  // Reading header comments
  //================================================
   while (auxStr == COMMENT) {
     comments_.push_back(readed);
     readed.clear();
     std::getline(inputFile, readed);
     std::cout << "Readed: " << readed << NEWLINE;
     auxStr = readed.substr (0,3);
     std::cout << "Auxstr: " << auxStr << NEWLINE;
     std::cout << "While comentario\n";
   }
   
     int temp;  //!< Used for store the amounts (alpabet symbols, states, etc.)
                //!< temporarily
     
     //================================
     // Reading the alphabet symbols
     //================================
     std::getline(inputFile, readed);  // Read the number of alphabet symbols
     temp = stoi(readed);
     readed.clear();
     char auxChar;

     for (int i = 0; i < temp; i++) {
       std::getline(inputFile, readed); 
       auxChar = readed[0];
       std::cout << "Auxchar:  " << auxChar << NEWLINE;
       alphabet_.insertAlphabet(auxChar);
       readed.clear();
     }

     //==============================
     // Reading of Dfa states
     //==============================
     std::getline(inputFile, readed);  // Read the number of automaton states.
     temp = stoi(readed); 
     readed.clear();

     for (int i = 0; i < temp; ++i) {
       std::getline(inputFile, readed);
       State auxState(readed);
       states_.insert(auxState);
       readed.clear();
     }

     //==============================
     // Reading of start state
     //==============================
     std::getline(inputFile, readed); // Read the star state.
     startState_ = readed;
     readed.clear();
     std::cout << "Start State: " << startState_ << NEWLINE;

     //==============================
     // Reading final states
     //==============================
     std::getline(inputFile, readed); // Read the number of final states.
     temp = stoi(readed);
     readed.clear();

     for (int i = 0; i < temp; ++i) {
       std::getline(inputFile, readed);
       finalStates_.insert(readed);
       readed.clear();
     }

     //================================
     // Reading automaton transitions
     //================================
     std::getline(inputFile, readed); // Read the number of transitions.
     temp = stoi(readed);
     readed.clear();

     std::string auxCurrentState;
     std::string auxInput;
     std::string auxDestination;
     char auxCharInput;
     
     for (int i = 0; i < temp; ++i) {
       std::getline(inputFile, readed);
       std::stringstream iss(readed);
       iss >> auxCurrentState;
       iss >> auxInput;
       iss >> auxDestination;
       
       Transition auxTransition(auxInput[0], auxCurrentState, auxDestination); 
       transitions_.insert(auxTransition);

       std::cout << "Current State: " << auxCurrentState << NEWLINE;
     }
  }
}


/**
* @brief Write in the output file the description of the DFA in DOT format.
* @param outputGv is the file where the DFA will be written in DOT format.
*/
void Dfa::drawDFA(std::string& outputGv) {
  std::ofstream outputFile;
  outputFile.open(outputGv);

  for (int i = 0; i < comments_.size(); ++i) {
    outputFile << comments_[i] << NEWLINE;
  }

  outputFile << "digraph DFA {" << NEWLINE;
  outputFile << S << S << "rankdir=LR;" << NEWLINE;
  outputFile << S << S << "size = \"10, 4\";" << NEWLINE;
  outputFile << S << S << "d2styleonly = true;" << NEWLINE;

  outputFile << S << S << "node [shape = none]; \"\"; " << NEWLINE;  // Dummy node for boot state
  outputFile << S << S << "node [shape = doublecircle];";

  for (auto i: finalStates_) {
    outputFile << " \"" << i << "\"";
  }
  outputFile << ";" << NEWLINE;

  outputFile << S << S << "node [shape = circle];" << NEWLINE;
  outputFile << S << S << "\"\" -> \"" << startState_ << "\";" << NEWLINE;

  for (auto i: transitions_) {
      outputFile << S << S << "\"" << i.getCurrent() << "\" -> ";
      outputFile << "\"" << i.getDestination() << "\" ";
      std::cout << "\"" << i.getDestination() << "\" ";
      outputFile << "[ label=\"" << i.getInput() << "\" ];" << NEWLINE;
      std::cout << "[ label=\"" << i.getInput() << "\" ];" << NEWLINE;
  }
  outputFile << "}" << NEWLINE;
}
