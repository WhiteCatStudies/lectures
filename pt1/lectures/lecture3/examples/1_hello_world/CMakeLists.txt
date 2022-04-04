# Минимально необходимая версия cmake
cmake_minimum_required(VERSION 3.16.3)

# имя проекта - hello world, весрсия - 1.0.0, язык - C/C++ 
project(helloworld VERSION 1.0.0 LANGUAGES CXX)

# установка опций компилятора или переменных, необходимых для сборки программы
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# поиск файлов библиотеки: бинарные файлы, заголовочные файлы и тд
# Что и как искать определяет модуль cmake Find<PackageName> 
# (см., например, в /usr/share/cmake-<version>/Modules/)
# Если библиотека поддерживает такой поиск, она предоставляет соотвествующий модуль,
# и он автоматически копируется в требуемую директорию при её установке
# свойство COMPONENTS позволяет выбрать определённые компоненты библиотеки
# Если выставлено свойство REQUIRED, отсутствие искомой библиотеки рассматривается
# как фатальная ошибка, и сборка прекращается    
find_package(Qt5 COMPONENTS Widgets REQUIRED)

# Исходный код исполняемого файла проекта находится в следующих файлах
# Здесь helloword - это таргет (target), цель сборки 
# (например, исполняемый файл или библиотека) 
add_executable(helloworld
               main.cpp
               )

# Компонует найденную ранее библиотеку
# Если заголовочные файлы библиотеки находятся не по стандартному системному пути,
# необходимо указать путь к ним при помощи target_include_direcories
target_link_libraries(helloworld Qt5::Widgets)
