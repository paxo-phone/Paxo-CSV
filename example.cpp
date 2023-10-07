#include <iostream>
#include <string>

#include "src/csv.hpp"

int main(int argc, char** argv)
{
    std::string data = "name,age,city\n"
                       "John,18,New-York\n"
                       "Edouard,34,Washington";

    csv::doc document (data);

    /**************************************************/
    std::cout << "** John Informations **" << std::endl;
    
    csv::row johnrow = document[1];

    for(int i = 0; i < johnrow.size(); i++)
        std::cout << johnrow[i] << std::endl;
    
    /*****************************************************/
    std::cout << "** Edouard Informations **" << std::endl;

    csv::row edouardrow = document[2];

    for(int i = 0; i < edouardrow.size(); i++)
        std::cout << edouardrow[i] << std::endl;

    
    /********************************************/
    std::cout << "** Add New Row **" << std::endl;

    csv::row newrow({"Steve", "16", "Cuppertino"});
    document.append(newrow);

    std::cout << document.tostring() << std::endl;

    return EXIT_SUCCESS;
}
