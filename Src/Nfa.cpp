/**
 * @Author Basilio Gómez Navarro
 * @date 3/11/2019
 * University of La Laguna
 * Higher School of Engineering and Technology
 * Computer Ingineering Degree
 * Grade: 2nd
 * Practice 7 - The Powerset Construction
 * Email: alu0101049151@ull.edu.es
 * Nfa.cpp file: Nfa class. It represents a Nondeterministic Finite Automaton.
 *               This file contains the class implementation. 
 * References:
 *                Practice statement:
 *                https://campusvirtual.ull.es/1920/pluginfile.php/181073/mod_assign/introattachment/0/CYA_1920_Practica_7.pdf?forcedownload=1
 * Revision history:
 *                3/11/2019 - Creation (first version) of the code
 */

#include "Nfa.h"

Nfa::Nfa(std::string& inputFile) {
  readAndBuildNfa(inputFile);
}


Nfa::Nfa(const Nfa& nfa):
  startState_(nfa.startState_),
  states_(nfa.states_),
  finalStates_(nfa.finalStates_),
  alphabet_(nfa.alphabet_),
  transitions_(nfa.transitions_),
  comments_(nfa.comments_) {}

Nfa::Nfa() {}


Nfa::~Nfa() {}


/**
* Returns the start state identifier.
*/
std::string Nfa::getStartState() const {
  return startState_;
}


/**
* Returns the set of states of the automaton.
*/
std::set<State> Nfa::getStates() const {
  return states_;
}


/**
* Returns the set of the final states identifiers.
*/
std::set<std::string> Nfa::getFinalStates() const {
  return finalStates_;
}


/**
* Returns the set of chars that represents the alphabet of the
* automaton.
*/
Alphabet Nfa::getAlphabet() const {
  return alphabet_;
}


/**
* Returns the vector containing all the comments read from the input file.
*/
std::vector<std::string> Nfa::getComments() const {
  return comments_;
}


/**
* Returns the set of transitions of the automaton.
*/
std::set<Transition> Nfa::getTransitions() const {
  return transitions_;
}


/**
* Reads the input file and builds the Nfa.
*/
void Nfa::readAndBuildNfa(std::string& nfaDefinition) {
  std::ifstream inputFile;
  inputFile.open(nfaDefinition);

  if (!inputFile.is_open()) {
    std::cerr << "There was a problem opening the inputfile, ";
    std::cerr << "please, try again." << NEWLINE;
  }
  else {
   std::string readed;      //!< Stores what is read every time we read a line from the file

   std::getline(inputFile, readed);
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
     auxStr = readed.substr (0,3);
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

     std::getline(inputFile, readed);  //Read the ~ (epsilon) symbol.
     auxChar = readed[0];
     std::cout << "Auxchar:  " << auxChar << NEWLINE;
     alphabet_.insertAlphabet(auxChar);
     readed.clear();

     for (int i = 0; i < temp; i++) {
       std::getline(inputFile, readed);
       auxChar = readed[0];
       std::cout << "Auxchar:  " << auxChar << NEWLINE;
       alphabet_.insertAlphabet(auxChar);
       readed.clear();
     }

     //==============================
     // Reading of DFA states
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
     }
  }
}

/**
* Powerset Construction algorithm.
*/
void Nfa::powersetConstruction(std::string& outputFile) {
  std::set<std::pair<std::string,std::set<State> > > statesDFA; //To indicate that it's unchecked uses the tag "@"
  std::set<State> T;
  std::set<State> q0;
  State auxStart(startState_);
  T.insert(auxStart);
  bool repeat = true;
  bool found = false;
  int auxStateId = 0;
  std::string auxStr;

  q0 = epsilonClosure(T);
  statesDFA.insert(std::pair<std::string, std::set<State> >(UNCHECKED, T) );
  
  while (repeat) {
    repeat = false;
    found = false;
    for (auto i: statesDFA) {
     if (!found) {
      if (i.first == UNCHECKED) {
        repeat = true;
        found = true;
        auxStr = std::to_string(auxStateId);
        i.first = auxStr;  // Check the state.
        auxStateId++;
        auxStr.clear();
      }
      for (auto j: alphabet_.getAlphabet()) {
        if (j != EPSILON) {
          std::set<State> auxSet;
          std::set<State> H;
          auxSet = move(i, j); //move (T,a);
          H = epsilonClosure(auxState);
          
          if (statesDFa.find(H) == statesDFA.end()) {
            statesDFA.insert(std::pair<std::string, std::set<State>
            >(UNCHECKED, H);
          }
        }
      }
     }
    }
  }
}


/**
* @brief Carries out the epsilon-closure of a set of states.
* @param toAnalize is the state to which the algorithm will be applied.
*/
std::set<State> Nfa::epsilonClosure(std::set<State> T) {
  std::stack<State> auxStack;
  std::set<State> eClosure;

  for (auto i: T) {
    auxStack.push(i);
  }
  eClosure = T;

  while (!auxStack.empty()) {
    State p;
    p = auxStack.top();
    auxStack.pop();
    bool found = false;

    for (auto i: transitions_) {
      if (i.getCurrent() == p.getStateId() && (i.getInput() == EPSILON)) {
        found = false;
        for (auto j: eClosure) {
          if (j.getStateId() == i.getDestination())
            found = true;
        }
        if (!found) {
          for (auto j: states_) {
            if (j.getStateId() == i.getDestination()) {
              eClosure.insert(j);
              auxStack.push(j);
            }
          }
        }
      }
    }
  }
  return eClosure;
}
