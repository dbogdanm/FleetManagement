FleetManagement

## ✍️Project description
A C++ application for fleet management, designed for tracking and managing drivers, vehicles, and routes efficiently. The project supports adding, updating, and removing entities, as well as calculating route distances and tracking vehicle mileage and driver hours. 

**NOTE: This repository contains only the backend code. If you're looking for the complete app, please refer to [this link](https://github.com/dbogdanm/QT-OOP)**.
## Milestone #0

- [ ] FleetManagement
- [ ] **`FleetEase`** is a fleet management app developed entirely in C++ using the QT framework (check my [other](https://github.com/dbogdanm/QT-OOP) repo ). It provides functionalities like managing vehicles, routes and permissions, making it a comprehensive tool for fleet administration.


## ❔**How can I use it❔**

   ## 🟢***METHOD 1***

   **1. Download QT Framework (preferably version 14.0.2)**

   **2. Download my [other](https://github.com/dbogdanm/QT-OOP) repo and build it inside QT.**

   ## 🔵***METHOD 2***
          
   **Just simply `git clone https://github.com/dbogdanm/QT-OOP` inside QT dev environment's terminal and build the project.**
      Now you should see something like [this](https://media.discordapp.net/attachments/757656608137412719/1305835843013054524/image.png?ex=6746eee6&is=67459d66&hm=f7323c0e399c838e2ea1bf9a2402d8502f7b7d0ec8bbdc13a41cb5aa492081b8&=&format=webp&quality=lossless&width=760&height=488) and like [this](https://media.discordapp.net/attachments/757656608137412719/1305654537327218698/image.png?ex=6746eecb&is=67459d4b&hm=e83afe023d413a8d10301521d2e14d6a94e48c3fd4ae4ae95b5d54e5f1e484cc&=&format=webp&quality=lossless&width=868&height=469). 
      
      
   
## Milestone #1

#### Cerințe
- [ ] definirea a minim **3-4 clase** folosind compunere cu clasele definite de voi
- [ ] constructori de inițializare cu parametri
- [ ] pentru o aceeași (singură) clasă: constructor de copiere, `operator=` de copiere, destructor
- [ ] `operator<<` pentru toate clasele pentru afișare (std::ostream)
- [ ] cât mai multe `const` (unde este cazul)
- [ ] implementarea a minim 3 funcții membru publice pentru funcționalități specifice temei alese, dintre care cel puțin 1-2 funcții mai complexe
  - nu doar citiri/afișări sau adăugat/șters elemente într-un/dintr-un vector
- [ ] scenariu de utilizare a claselor definite:
  - preferabil sub formă de teste unitare, mai ales dacă vorbim de aplicații consolă 
  - crearea de obiecte și apelarea tuturor funcțiilor membru publice în main
  - vor fi adăugate în fișierul `tastatura.txt` DOAR exemple de date de intrare de la tastatură (dacă există); dacă aveți nevoie de date din fișiere, creați alte fișiere separat
- [ ] tag de `git`: de exemplu `v0.1`
- [ ] serviciu de integrare continuă (CI); exemplu: GitHub Actions

## Milestone #2

#### Cerințe
- [ ] separarea codului din clase în `.h` (sau `.hpp`) și `.cpp`
- [ ] moșteniri:
  - minim o clasă de bază și **3 clase derivate** din aceeași ierarhie
  - ierarhia trebuie să fie cu bază proprie, nu derivată dintr-o clasă predefinită
  - [ ] funcții virtuale (pure) apelate prin pointeri de bază din clasa care conține atributul de tip pointer de bază
    - minim o funcție virtuală va fi **specifică temei** (e.g. nu simple citiri/afișări)
    - constructori virtuali (clone): sunt necesari, dar nu se consideră funcții specifice temei
    - afișare virtuală, interfață non-virtuală
  - [ ] apelarea constructorului din clasa de bază din constructori din derivate
  - [ ] clasă cu atribut de tip pointer la o clasă de bază cu derivate; aici apelați funcțiile virtuale prin pointer de bază, eventual prin interfața non-virtuală din bază
    - [ ] suprascris cc/op= pentru copieri/atribuiri corecte, copy and swap
    - [ ] `dynamic_cast`/`std::dynamic_pointer_cast` pentru downcast cu sens
    - [ ] smart pointers (recomandat, opțional)
- [ ] excepții
  - [ ] ierarhie proprie cu baza `std::exception` sau derivată din `std::exception`; minim **3** clase pentru erori specifice
  - [ ] utilizare cu sens: de exemplu, `throw` în constructor (sau funcție care întoarce un obiect), `try`/`catch` în `main`
  - această ierarhie va fi complet independentă de ierarhia cu funcții virtuale
- [ ] funcții și atribute `static`
- [ ] STL
- [ ] cât mai multe `const`
- [ ] funcții *de nivel înalt*, de eliminat cât mai mulți getters/setters/funcții low-level
- [ ] tag de `git`: de exemplu `v0.2`

## Milestone #3

#### Cerințe
- [ ] 2 șabloane de proiectare (design patterns)
- [ ] o clasă șablon cu sens; minim **2 instanțieri**
  - [ ] preferabil și o funcție șablon (template) cu sens; minim 2 instanțieri
- [ ] tag de `git`: de exemplu `v0.3` sau `v1.0`

## Resurse
- adăugați trimiteri către resursele externe care v-au ajutat sau pe care le-ați folosit
