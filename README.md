# Курс лекций по предмету Методы и стандарты программирования (МиСП)
Читается в МИРЭА на кафедре ПО РЭА во 2 (часть 1) и 3 (часть 2) семестрах с 2021 г.
Материалы к каждой лекции находятся в отдельной папке, пронумерованной в порядке чтения лекций на курсе, и состоят из презентации (вводная часть) и примеров с комментариями (основная часть, папка examples). Внутри папки examples примеры сгруппированы по темам лекции и пронумерованы в порядке обсуждения.
Компиляция примеров: g++ <все файлы в папке с расширением *.cpp>
Курс находится в процессе разработки.

## Первая часть
### [Лекция 1](pt1/lectures/lecture1)
1. Парадигмы программирования. 
2. Объектно ориентированное программирование (ООП) в C++
   * Объявление класса
   * Инкапсуляция
   * Классы и объекты
   * Конструкторы по умолчанию и с параметрами; перегрузка конструкторов
   * Состояние, поведение, идентичность
   * Статические и константные свойства и методы
   * Работа с объектами
   * Деструкторы
   * Классы vs структуры
   * Принципы объектно-ориентированного проектирования
3. [Ссылки vs. указатели и базовый ввод/вывод](pt1/lectures/lecture1/examples/2_pointers_references)

### [Лекция 2](pt1/lectures/lecture2)
1. Конструкторы копирования
2. Наследование
   * Порядок вызова конструкторов и деструкторов в иерархиях классов
   * Ромбовидное наследование (diamond problem)
3. Полиморфизм
   * Доступ к объекту производного класса через указатель на базовый класс
   * Виртуальные функции, полиморфные классы
   * Чисто виртуальные функции, абстрактные классы
   * Таблица виртуальных методов (vtable)
   * Статический (времени компиляции) и динамичесий (времени выплнения) полиморфизм
   
### [Лекция 3](pt1/lectures/lecture3)
1. Фреймворк Qt и система сборки cmake
   * Модули и инструменты фреймворка Qt
   * Hello world с Qt. Цикл событий
   * Основы работы с cmake
   * Виджеты
   * Иерархия классов Qt
   * Сигналы, слоты и их соединение
   * Процесс сборки проекта, использующего Qt: UIC и MOC

### [Лекция 4](pt1/lectures/lecture4)
1. Функции-друзья
2. Препроцессор C++
   * Опережающие определения и header guards
   * Директивы препроцессора
3. Указатель this
4. Перегрузка операторов

### [Лекция 5](pt1/lectures/lecture5)
1. Способы завершения программы
2. Обработка исключений:
  * Синтаксис C++ для работы с исключениями
  * Stack unwinding
  * Исключения пользовательсикх типов и использование иерархий классов для обработки исключений
  * Повторная генерация исключения
  * Ограничения на тип и генерацию исключений
  * Исключения и практика обработки ошибок
 

