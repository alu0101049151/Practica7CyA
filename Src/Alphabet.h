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
 *                  This file contains the class definition.
 * References:
 *                Practice statement:
 *                https://campusvirtual.ull.es/1920/pluginfile.php/176735/mod_assign/introattachment/0/CYA_1920_Practica_6.pdf?forcedownload=1
 * Revision history:
 *                27/10/2019 - Creation (first version) of the code
 */

#ifndef PRACTICE7_ALPHABET_H
#define PRACTICE7_ALPHABET_H

#include <set>
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

class Alphabet {
	
	public:
		Alphabet ();
		~Alphabet ();

		/**
		* @brief inserts a new symbol into the alphabet.
		* @param symbol is the new symbol to insert.
		*/
		void insertAlphabet (const char symbol);

    /**
    * @brief returns alphabet.
    */
    std::set<char> getAlphabet() const;

	private:
		std::set<char> alphabet_; //!< Character set representing the DFA's alphabet
};

#endif //PRACTICE7_ALPHABET_H

