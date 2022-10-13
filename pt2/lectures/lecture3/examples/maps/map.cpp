// https://en.cppreference.com/w/cpp/container/map
#include <map>
#include <iostream>
#include <string>


template <class MapT>
void printMap(const MapT& coll)
{
    for(const auto elem: coll)
    {
        std::cout << "[" << elem.first << "] = " << elem.second << "; ";
    }

    std::cout << "\n";
}


int main()
{

    std::map<std::string, int> m{{"CPU", 10}, {"GPU", 15}, {"RAM", 20}};
    std::cout << "Initial map\n";
    printMap(m);
    std::getchar(); 
 
    // Изменить значение по существующему ключу
    m["CPU"] = 25;
    std::cout << "Update CPU key\n";
    printMap(m);
    std::getchar();

    // Вставить новое значение
    std::cout << "Insert {SSD: 30}\n";
    m["SSD"] = 30;

    std::cout << "Insert {USB, 5}\n";
    const auto status = m.insert(std::pair<std::string, int>("USB", 5));
    if (status.second)
    {
        std::cout << "Element was inserted at position " << 
            std::distance(m.begin(), status.first) << "\n" <<
            "New element key is " << status.first->first << 
            "\nValue is " << status.first->second << "\n";
    }
    else
    {
        std::cout << "Element already exists\n";
    }

    std::cout << "Insert {LCD: 3}\n";
    m.insert(std::make_pair<std::string, int>("LCD", 3));
    std::cout << "Updated map\n";
    printMap(m);
    std::getchar();

    std::cout << "Get value by non-existing key\n";
    std::cout << m["HDD"] << std::endl;
    // Из документации про T& operator[](const Key& key):
    // Inserts value_type(key, T()) if the key does not exist. 
    // This function is equivalent to return insert(std::make_pair(key, T())).first->second;
    m["HDD"] = 2;    
    std::getchar();

    std::cout << "Change HDD value through iterator\n";
    const auto hdd = m.find("HDD");
    hdd->second = 3;
    // Не компилируется - ключ всегда константный
    // hdd->first = "SDD";
    printMap(m);
}