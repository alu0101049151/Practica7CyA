/**
 * @Author Basilio Gómez Navarro
 * @date 3/11/2019
 * University of La Laguna
 * Higher School of Engineering and Technology
 * Computer Ingineering Degree
 * Grade: 2nd
 * Practice 7 - The Powerset Construction
 * Email: alu0101049151@ull.edu.es
 * mainNFA2DFA.cpp file: This file contains the main function of the program.
 * References:
 *                Practice statement:
 *                https://campusvirtual.ull.es/1920/pluginfile.php/181073/mod_assign/introattachment/0/CYA_1920_Practica_7.pdf?forcedownload=1
 * Revision history:
 *                3/11/2019 - Creation (first version) of the code
 */


#include "Nfa.h"

int main (int argc, char const* argv[]) {

  if (argv[1] == NULL) {
    std::cout << "Usage: ./NFA2DFA input.nfa output.dfa\n";
    std::cout << "Try 'NFA2DFA --help' for more information\n";
  } 
  else {
    std::string inputFile = argv[1];

    if (inputFile  == "--help") {
      std::cout << "NAME\n";
      std::cout << "      NFA2DFA\n";
      std::cout << "\n";
      std::cout << "USAGE:\n";
      std::cout << "      NFA2DFA [input_file.nfa] [output_file.dfa]\n";
      std::cout << "\n";
      std::cout << "DESCRIPTION\n";
      std::cout << "      Reads a \".nfa\" input file with the definition of a\n";
      std::cout << "      Nondeterministic Finite Automaton and generates a\n";
      std::cout << "      \".dfa\" output file with the DFA specification\n";
      std::cout << "      resulting from applying to the NFA the Powerset\n"; 
      std::cout << "      Construction.";
      std::cout << "\n";
      std::cout << "AUTHOR\n";
      std::cout << "      Written by Basilio Gómez Navarro as practice of the\n";
      std::cout << "      subject Computability and Algorithm. November of 2019.\n";
      std::cout << "\n\n";
    }
  else {
    std::string outputFile = argv[2];

    Nfa nfa(inputFile);
  }
 }
  return 0;
}

