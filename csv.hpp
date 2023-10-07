/**
 * @author Raphaël Goutmann
 * @file csv.hpp
 * @brief Librairie CSV pour le PaxOS
*/

#ifndef __LIB_CSV__
#define __LIB_CSV__

#include <string>
#include <vector>

#define CSV_COL_SEPARATOR ','
#define CSV_ROW_SEPARATOR '\n'

namespace csv
{
    /**
     * @class row
     * @brief Cette classe représente une ligne d'un fichier csv
    */
    class row
    {
        public:

            /**
             * @brief Construit une ligne csv vide
            */
            row();

            /**
             * @brief Construit une ligne csv à partir d'une chaine de caractère (string)
            */
            row(const std::string& _str);

            /**
             * @brief Construit une ligne à partir de la liste de ses valeurs sous forme de std::vector<std::string>
            */
            row(const std::vector<std::string>& _data);

            /**
             * @brief Lis les données d'une ligne depuis une chaine de caractères (std::string)
            */
            void parse(const std::string& _str);

            /**
             * @brief Retourne le nombre d'éléments présents dans la ligne
            */
            size_t size(void);

            /**
             * @brief Retourne le ième élément de la ligne
            */
            std::string operator[](const size_t& _i);

            /**
             * @brief Ajoute un élément à la ligne csv
            */
            void append(const std::string& _cell);
            
            /**
             * @brief Convertit la ligne en une chaine de caractères
            */
            std::string tostring(void);

            /**
             * @brief Vide la ligne csv
            */
            void clear(void);

            /**
             * @brief Retourne true si la ligne est vide, false dans le cas contraire
            */
           bool empty(void);

        private:

            std::vector<std::string> m_cells;

    };

    /**
     * @class doc
     * @brief Cette classe représente un document csv
    */

    class doc
    {
        public:

            /**
             * @brief Construit un document csv vide
            */
            doc();

            /**
             * @brief Construit un document csv à partir d'une chaine de caractères (std::string)
            */
            doc(const std::string& _str);
            
            /**
             * @brief Construit un document à partir d'un tableau de données (std::vector<std::vector<std::string>>)
            */
           doc(const std::vector<std::vector<std::string>>& _data);

            /**
             * @brief Lis les données du document csv à partir d'une chaine de caractères (std::string)
            */
            void parse(const std::string& _str);
            
            /**
             * @brief Retourne le nombre de lignes du document csv
            */
            size_t size(void);

            /**
             * @brief Retourne la ième ligne du document csv
            */
            row operator[](const size_t& _i);

            /**
             * @brief Ajoute une ligne au document csv
            */
            void append(const row& _row);

            /**
             * @brief Convertit le document csv en une chaine de caractères
            */
            std::string tostring(void);

            /**
             * @brief Vide le document csv
            */
           void clear(void);

           /**
            * @brief Retourne true si le document vide, false dans le cas contraire
           */
          bool empty(void);

        private:

            std::vector<row> m_rows;

    };

}

#endif /* __LIB_CSV__ */