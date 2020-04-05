**Premessa**: il progetto implementa molti piu' dettagli di quelli richiesti per
la consegna

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


* `FixedVector` Class:
    - classe con template
    - constexpr
    - override `operator+` (semplice)


* `LAObject` Class:
    - classe con template
    - metodi `pure virtual`


* `Vector` Class:
    - classe con template e specializzazione nel file .cpp
    - override dei metodi `print()` `size()`
    - overloading `operator[]` (const/non-const)
    - friend `operator+` (avanzato)
    - friend `operator*` (avanzato)
    - template friend class


* `Matrix` Class:
    - classe con template e implementazione nel file .i.hpp
    - override dei metodi `print()` `size()`
    - overloading `operator[]` (const/non-const)
    - friend `operator+` (avanzato)
    - friend `operator*` (avanzato)


* `Operator` file:
    - implementazione nel file .i.hpp
    - overloading operator+
    - overloading operator*


* `Util` file:
    - funzione `inline`
    - decorator `[[noreturn]]`


* `Test` file:
    - test funzionalita' di base e polimorfismo


* **Altri note**:
    - codice all'interno di `namespace`
    - construttore marcati `explicit`
    - libreria `catch2` per il testing
    - metodi marcati `const`
    - Doxygen: parametri in/out, WARNINGS = YES
    - distinzione tra variabili di classe e non (prefisso `_`)
    - nome consistenti tra `include`, `src`, `include/impl`
