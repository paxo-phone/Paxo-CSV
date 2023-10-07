#include <string>

#include "csv.hpp"

namespace csv
{
    row::row()
    {}

    row::row(const std::string& _str)
    {
        this->parse(_str);
    }

    row::row(const std::vector<std::string>& _data)
    {
        this->m_cells = _data;
    }

    void row::parse(const std::string& _str)
    {
        int i = 0;
        std::string temp = "";

        while(i < _str.size())
        {
            if(_str[i] == CSV_ROW_SEPARATOR)
                break;
            
            else if(_str[i] == CSV_COL_SEPARATOR)
            {
                this->m_cells.push_back(temp);
                temp.clear();
            }
            else
            {
                temp += _str[i];
            }

            i++;
        }

        this->m_cells.push_back(temp);
    }

    size_t row::size(void)
    {
        return this->m_cells.size();
    }

    std::string row::operator[](const size_t& _i)
    {
        return this->m_cells[_i];
    }

    void row::append(const std::string& _cell)
    {
        this->m_cells.push_back(_cell);
    }

    std::string row::tostring(void)
    {
        std::string o = "";

        for(int i = 0; i < this->m_cells.size(); i++)
        {
            o += this->m_cells[i];
            if( i != this->m_cells.size() - 1)
                o += CSV_COL_SEPARATOR;
        }

        return o;
    }

    void row::clear(void)
    {
        this->m_cells.clear();
    }

    bool row::empty(void)
    {
        return this->m_cells.empty();
    }

    doc::doc()
    {}

    doc::doc(const std::string& _str)
    {
        this->parse(_str);
    }
    
    doc::doc(const std::vector<std::vector<std::string>>& _data)
    {
        for(auto& _row : _data)
        {
            row temp (_row);
            this->append(temp);
        }
    }

    void doc::parse(const std::string& _str)
    {
        int i = 0;
        row tempRow;
        std::string temp = "";

        while(i < _str.size())
        {
            if(_str[i] == CSV_ROW_SEPARATOR)
            {
                tempRow.append(temp);
                temp.clear();

                this->append(tempRow);
                tempRow.clear();
            }
            
            else if(_str[i] == CSV_COL_SEPARATOR)
            {
                tempRow.append(temp);
                temp.clear();
            }
            else
            {
                temp += _str[i];
            }

            i++;
        }

        if( !temp.empty() )
            tempRow.append(temp);
        
        if( !tempRow.empty() )
            this->append(tempRow);

        
    }

    size_t doc::size(void)
    {
        return this->m_rows.size();
    }

    row doc::operator[](const size_t& _i)
    {
        return this->m_rows[_i];
    }

    void doc::append(const row& _row)
    {
        this->m_rows.push_back(_row);
    }

    std::string doc::tostring(void)
    {
        std::string o = "";

        for(int i = 0; i < this->m_rows.size(); i++)
        {
            o += m_rows[i].tostring();
            if( i != m_rows.size() - 1 )
                o += CSV_ROW_SEPARATOR;
        }

        return o;
    }

    void doc::clear(void)
    {
        this->m_rows.clear();
    }

    bool doc::empty(void)
    {
        return this->m_rows.empty();
    }


}