# Knapsack-Problem-C-and-Py
Un pescar exploreaza o regiune de coasta bogata in homari, fiecare avand propria sa dimensiune (in centimetri) si valoare(in monede de aur). Plasa pescarului are o capacitate limitata, exprimata in numarul total de centimetric pe care ii poate contine. Avand o lista detaliata cu dimensiunile si valorile homarilor disponibili in acea regiune, sarcina este sa se elaboreze o strategie prin care pescarul sa selecteze homarii in asa fel incat sa maximizeze valoarea totala a capturii, respectand in acelasi timp limita de capacitate a plasei. Trebuie sa se decida care homari sa fie inclusi in plasa si care sa fie lasati, astfel incat suma valorilor homarilor selectati sa fie cea mai mare posibila, fara ca suma dimensiunilor acestora sa depaseasca capacitatea plasei. Imaginati-va un scenario in care un pescar are oportunitatea de a alege dintre o selectie de homari, fiecare cu o dimensiune si o valoare sepcificate, pentru a umple plasa sa care are o capacitate maxima. Scopul pescarului este de a maximiza valoarea totala a capturii sale fara depasi limita de dimensiune a plasei. Iata un exemplu: Homari disponibili: • Homarul A: Dimensiune = 4 cm, Valoare = 20 monede de aur • Homarul B: Dimensiune = 3 cm, Valoare = 15 monede de aur • Homarul C: Dimensiune = 2 cm, Valoare = 10 monede de aur • Homarul D: Dimensiune = 5 cm, Valoare = 25 monede de aur Capacitatea plasei: 10 cm Provocarea este de a selecta combinatia de homari care maximizeaza valoarea totala fara a depasi o dimensiune totala de 10cm. O posibila solutie ar implica alegerea homarilor A si C, oferindu-ne o dimensiune totala de 6cm( 4 cm + 2 cm ) si o valoare totala de 30 monede de aur ( 20 + 10 ). Totusi, o solutie mai buna ar fi sa alegem homarii B, C si D, care impreuna au o dimensiune totala de 10 cm( 3 cm + 2 cm + 5 cm) si ofera o valoare totala mai mare de 50 monede de aur( 15 + 10 + 25). Aceasta combiantie umple exact capacitatea plasei si maximizeaza valoarea capturii.

Proiect C
Instrucțiuni de Compilare
Navigați în directorul principal al proiectului:

cd "C Code"
Compilați proiectul folosind Makefile-ul:

make
Această comandă va compila toate fișierele sursă și va crea executabilul bin/app.

Executați programul compilat:

După ce procesul de compilare este complet, executabilul va fi generat în folderul bin. Pentru a rula programul, utilizați următoarea comandă:

./bin/app
Dependențe
Asigurați-vă că aveți instalat un compilator C (precum gcc) și utilitarul make. Puteți instala aceste unelte pe un sistem bazat pe Debian (precum Ubuntu) utilizând următoarele comenzi:

sudo apt-get update
sudo apt-get install build-essential
