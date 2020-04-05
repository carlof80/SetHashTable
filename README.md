## Cosa include il progetto ##

* `CMakeLists.txt`
    - compilazione con warning
    - modalita' RELEASE, DEBUG, e SANITIZE
    - *valgrind* target (`make valgrind`)
    - *code complexity* target (`make cyclo`)
    - *count lines of code* target (`make stats`)
    - *coverage* target (`make coverage`)
    - *linter* target (`make tidy`)
    - *static analysis* target (`make scan`)
    - test (`make test`)
    - clean all (doc, build, etc.) (`make clean-all`)

* `HashNode` Class:
    Questa classe implementa un nodo della tabella, composto da key e value.   
    - classe con template
    - construttore marcato `explicit`
    - costruttore `default`
    - passaggio parametri per puntatore e reference

* `HashSet` Class:
    Questa classe implementa un dizionario composto da HashNode generici.
    Questa classe è astratta, per la presenza di un metodo virtuale puro.
    - classe con template
    - metodo `pure virtual`
    - implementazione iteratore interno (`Iterator` Class)
    - variabile `static`
    - metodi virtuali
    - override `operator++`
    - override `operator*`
    - override `operator!=`
    - override `operator[]`
    - uso tipo `size_t` per variabili intere
    - inserimento con algoritmi `Linear Probing` (LP) e `Quadratic Probing` (QP)

* `HashSetInt` Class:
    Classe derivata da HashSet.
    Questa classe implementa un dizionario composto da HashNode con key e value interi.
    E' usata a fine di test.
    - class inheritance
    - override e implementazione metodo `sprint()` per rendere la classe concreta
    - utilizzo polimorfismo in late binding

* `HashSetItem` Class:
    Classe derivata da HashSet.
    Questa classe implementa un dizionario composto da HashNode con key intera e value puntatore a Item.
    E' usata per la gestione dello Store.
    - class inheritance
    - override e implementazione metodo `sprint()` per rendere la classe concreta
    - utilizzo polimorfismo in late binding

* `Item` Class:
    Questa classe implementa un generico prodotto di un magazzino.
    - overloading costruttori
    - delegate constructor
    - utilizzo lambda

* `ElectronicDevice` Class:
    Classe derivata da Item.
    Questa classe implementa un Item di tipo ElectronicDevice.
    - override metodo `sprint()`

* `ElectronicDeviceType` enum class:
    Questa enumeration elenca tutti i tipi di ElectronicDevice.
    - utilizzo enum class

* `Food` Class:
    Classe derivata da Item.
    Questa classe implementa un Item di tipo Food.
    - override metodo `sprint()`

* `FoodType` enum class:
    Questa enumeration elenca tutti i tipi di Food.
    - utilizzo enum class

* `Beverage` Class:
    Classe derivata da Item.
    Questa classe implementa un Item di tipo Beverage.
    - override metodo `sprint()`

* `BeverageType` enum class:
    Questa enumeration elenca tutti i tipi di Beverage.
    - utilizzo enum class

* `PersonalCareProduct` Class:
    Classe derivata da Item.
    Questa classe implementa un Item di tipo PersonalCareProduct.
    - override metodo `sprint()`

* `PersonalCareProductType` enum class:
    Questa enumeration elenca tutti i tipi di PersonalCareProduct.
    - utilizzo enum class

* `Store` Class:
    Questa classe implementa un magazzino.
    - passaggio parametri per valore
    - range-based for loop
    - `dynamic_cast`

* `Test` file:
    - test funzionalita' di base e polimorfismo

* **Altri note**:
    - codice all'interno di `namespace`
    - libreria `catch2` per il testing
    - metodi marcati `const`
    - Doxygen: parametri in/out, WARNINGS = YES
    - distinzione tra variabili private e non (prefisso `_`)
    - nome consistenti tra `include`, `src`
