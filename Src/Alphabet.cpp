/**
 * @Author Basilio Gómez Navarro
 * @date 27/10/2019
 * University of La Laguna
 * Higher School of Engineering and Technology
 * Computer Ingineering Degree
 * Grade: 2nd
 * Practice 6 - Deterministic Finite Automaton
 * Email: alu0101049151@ull.edu.es
 * Alphabet.h file: Alphabet class. It represents the alphabet of the DFA
 *                  This file contains the class implementation.
 * References:
 *                Practice statement:
 *                https://campusvirtual.ull.es/1920/pluginfile.php/176735/mod_assign/introattachment/0/CYA_1920_Practica_6.pdf?forcedownload=1
 * Revision history:
 *                27/10/2019 - Creation (first version) of the code
 */

 #include "Alphabet.h"

Alphabet::Alphabet () {}

Alphabet::~Alphabet () {}

/**
* Inserts the symbol passed as a parameter in the alphabet. 
*/
void Alphabet::insertAlphabet (const char symbol) {
	alphabet_.insert(symbol);
}

/**
* @brief returns alphabet.
*/
std::set<char> Alphabet::getAlphabet() const {
  return alphabet_;
}

