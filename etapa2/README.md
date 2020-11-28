# Etapa 2
## Ignat Andrei-Horia 324CA

## Folder-ul in
Contine 10 teste de input generate cu ajutorul lui **tests_generator**, care vor
testa corectitudinea implementarii celor 2 algoritmi.

## Folder-ul out
Contine doua foldere, **out1** si **out2** (fiecare algoritm cu folder-ul sau)
in care se vor scrie rezultate obtinute in urma executiei programului.

Fiecare director de output, contine cate 10 fisiere corespunzatoare testelor de
input.

## Folder-ul ref
Contine 10 fisiere in care sunt trecute rezultatele corecte pentru fiecare test
de input.

## tests_generator.py
Creez cate un test de input si un fisier de tip ref dupa modelul urmator:

*make_single_test(numar_test, limita_inferioara, limita_superioara,
                  numar_prime, numar_compuse, numar_carmichael)*

Fiecare test de input va contine *numar_prime* numere prime, *numar_compuse*
numere compuse, *numar_carmichael* numere Carmichael (sau maximul de numere 
prime / compuse dintr-un *inteval*), toate acestea fiind in *intervalul*
\[limita_inferioara, limita_superioara\].

Folosesc **Ciurul lui Eratostene** pentru a genera toate numerele prime mai mici
decat un numar dat si apoi le aleg pe cele mai mari decat o limita inferioara.
Totodata, acest algoritm imi va da informatii si despre numerele compuse.

Amestec numerele prime cu cele compuse din intervalul dorit, la care adaug si nu-
mere Carmichael, iar aceasta lista va forma input-ul dintr-un fisier. Testul din
ref va contine lista cu numere prime generata de ciur.

## main.cpp
Are forma unui checker, care va apela cei doi algoritmi generand rezultatele ob-
tinute in fisierele de output corespunzatoare. Ulterior, va compara output-ul cu
ref-ul, printand un mesaj in functie de corectitudine.

Afisez informatii si despre timpul de executiei in *microsecunde*, al fiecarui al-
goritm, pentru fiecare test.

## Algoritmii
Codul pentru fiecare algoritm se afla in **algo1** si respectiv **algo2**. Ambii
algoritmi determina numerele prime dintr-o secventa de numere data.

### algo1
Implementeaza **Fermat primality test**, dupa modelul de pe [GeeksforGeeks](https://www.geeksforgeeks.org/primality-test-set-2-fermet-method/).

### algo2
Implementeaza **Miller-Rabin primality test**, dupa modelul de pe [GeeksforGeeks](https://www.geeksforgeeks.org/primality-test-set-3-miller-rabin/).

## Makefile
Contine o regula de:
**build**, care compileaza toate fisierele .cpp;
**run_tests**, care ruleaza main.cpp;
**clean**, care sterge fisierele obiect si executabilul.

