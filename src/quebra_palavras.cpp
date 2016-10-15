/**
 * @name  Diogo Dantas
 * @date  15-10-2016
 */

 #include "../inc/quebra_palavras.hpp"


 bool dinamica::quebra_palavras(std::vector<std::string> & dictionary, std::string str){

 	size_t size = str.size();
 	Dictionary* dic =  new Dictionary(dictionary);

 	if (!size)
 		return true;

    bool wb[size+1];
    memset(wb, 0, sizeof(wb)); // Inicializando os valores.
 
    for (int i=1; i<=size; i++)
    {
        if (wb[i] == false && dic->dictionary_contais( str.substr(0, i) ))
            wb[i] = true;
 
        if (wb[i] == true)
        {
            if (i == size)
                return true;
 
            for (int j = i+1; j <= size; j++)
            {
                if (wb[j] == false && dic->dictionary_contais( str.substr(i, j-i) ))
                    wb[j] = true;
 
                if (j == size && wb[j] == true)
                    return true;
            }
        }
    }
    
    return false;
 }