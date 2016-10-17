/**
 * @name  Diogo Dantas
 * @date  15-10-2016
 */

#ifndef WORD_BREAK_HPP
#define WORD_BREAK_HPP

#include <vector>
#include <string>
#include <string.h>

 namespace dynamic {

 	class Dictionary {
 	private:
 		std::vector<std::string> dictionary;
 		int num_words;

 	public:
 		Dictionary(std::vector<std::string> & dictionary){
 			this->dictionary = dictionary;
 			this->num_words = dictionary.size();
 		}
 		bool dictionary_contais(const std::string word){

 			for (std::vector<std::string>::iterator it = this->dictionary.begin(); it != this->dictionary.end(); ++it)
 			{
 				if(*it == word)
 					return true;
 			}

 			return false;
 		}
 	};

 	/**
 	 * @brief  {Função que verifica se um string qualquer pode ser separada em palavras conhecidas
 	 *         	que estão armazenadas em um dicionário}
 	 *
 	 * @param  dictionary 	O dicionario que será utilizado para consulta
 	 * @param  str        	A string que será quebrada
 	 */
 	bool word_break(std::vector<std::string> & dictionary , std::string str);

 }


#endif // WORD_BREAK_HPP
