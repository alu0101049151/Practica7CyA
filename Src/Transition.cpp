/**
 * @Author Basilio Gómez Navarro
 * @date 27/10/2019
 * University of La Laguna
 * Higher School of Engineering and Technology
 * Computer Ingineering Degree
 * Grade: 2nd
 * Practice 6 - Deterministic Finite Automaton
 * Email: alu0101049151@ull.edu.es
 * Transition.cpp file: Transition class. It represents a transition between the
 *                      current state and another state of the automaton. The 
 *                      destination depends on the entry that reaches the current 
 *                      state. This file contains the class implementation.
 * References:
 *                Practice statement:
 *                https://campusvirtual.ull.es/1920/pluginfile.php/176735/mod_assign/introattachment/0/CYA_1920_Practica_6.pdf?forcedownload=1
 * Revision history:
 *                27/10/2019 - Creation (first version) of the code
 */

#include "Transition.h"

Transition::Transition(char input, std::string current, std::string destination):
	input_(input),
  current_(current),
	destination_(destination) {}


Transition::Transition(const Transition& transition):
	input_(transition.input_),
  current_(transition.current_),
	destination_(transition.destination_) {}


Transition::~Transition() {}


char Transition::getInput() const {
	return input_;
}


std::string Transition::getDestination() const {
	return destination_;
}


/**
* Returns the id of the current state.
*/
std::string Transition::getCurrent() const {
  return current_;
}


int Transition::operator< (const Transition& transition) const {
	if (this->current_ < transition.current_) return 1;
	if (this->current_ == transition.current_ && this->destination_ < transition.destination_) return 1;
	return 0;
}
