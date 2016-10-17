/**
 * @name  Diogo Dantas
 * @date  15-10-2016
 */

 #include "../inc/word_break.hpp"


 bool dynamic::word_break(std::vector<std::string> & dictionary, std::string str){

 	size_t size = str.size();
    //Criando o dicionário que será utilizado nas consultas
 	Dictionary* dic =  new Dictionary(dictionary);

    //Se o tamanho da string for zero a função retorna imediatamente
 	if (!size)
 		return true;

    //Criando a tabela que será utilizada para armazenar os resultados dos subproblemas
    bool wb[size+1];
    memset(wb, 0, sizeof(wb)); // Inicializando os valores como zero

    for (int i=1; i<=size; i++)
    {
        //Se wb = false devemos testar o prefixo atual
        if (wb[i] == false && dic->dictionary_contais( str.substr(0, i) ))
            wb[i] = true;

        //Se wb = true devemos procurar por todas as substrings que iniciam na posição (i+1)
        if (wb[i] == true)
        {
            //Quando chegamos no último prefixo
            if (i == size)
                return true;

            for (int j = i+1; j <= size; j++)
            {
                //Se wb[j] = false podemos atualizar seu valor
                if (wb[j] == false && dic->dictionary_contais( str.substr(i, j-i) ))
                    wb[j] = true;

                //Quando chegamos no último char
                if (j == size && wb[j] == true)
                    return true;
            }
        }
    }
    //Se todos os prefixos foram testados e nenhum deles está no dicionário devemos retornar false
    return false;
 }
