/**
 * @Author Basilio Gómez Navarro
 * @date 27/10/2019
 * University of La Laguna
 * Higher School of Engineering and Technology
 * Computer Ingineering Degree
 * Grade: 2nd
 * Practice 6 - Deterministic Finite Automaton
 * Email: alu0101049151@ull.edu.es
 * State.cpp file: State class. It represents a state of a 
 *               Deterministic Finite Automaton.
 *               This file contains the class implementation. 
 * References:
 *                Practice statement:
 *                https://campusvirtual.ull.es/1920/pluginfile.php/176735/mod_assign/introattachment/0/CYA_1920_Practica_6.pdf?forcedownload=1
 * Revision history:
 *                27/10/2019 - Creation (first version) of the code
 */

#include "State.h"

State::State(std::string stateId):
	stateId_(stateId) {}

State::State() {}

State::State(const State& state):
	stateId_(state.stateId_) {}


State::~State() {}


std::string State::getStateId() const {
	return stateId_;
}


int State::operator< (const State& state) const {
	if (this->stateId_ == state.stateId_) return 1;
	if (this->stateId_ < state.stateId_) return 1;
	return 0;
}
