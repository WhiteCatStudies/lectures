# Курс лекций по предмету Методы и стандарты программирования (МиСП)
Читается в МИРЭА кафедре ПО РЭА во 2 (часть 1) и 3 (часть 2) семестрах с 2021 г.
Курс находится в процессе разработки

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
Фреймворк Qt и система сборки cmake
    * Модули и инструменты фреймворка Qt
    * Hello world с Qt. Цикл событий
    * Основы работы с cmake
    * Виджеты
    * Иерархия классов Qt
    * Сигналы, слоты и их соединение
    * Процесс сборки проекта, использующего Qt: UIC и MOC
