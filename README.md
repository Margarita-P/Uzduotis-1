# Versija-0.2  
Tai Versijos 0.1 papildymas.  
Atsakius į klausimą "Ar norite patys įvesti patys įvesti studento duomenis(t), ar norite, kad jie būtų nuskaityti iš failo (n)?: " t, programa darys viską ką daro Versija 0.1 ir dar galima papildomai pasirinkti ar iškart žinoma kiek bus studentų, ar ne.  
Jei atsakoma taip (t), reikia įrašyti kiek bus studentų, ir tiek studentų duomenų įvesti.  
Jei atsakoma ne (n), gale kiekvieno studento duomenų įrašymo reikia atsakyti į klausimą "Ar norite pridėti dar vieną studentą? "  
Jei atsakoma taip (t), iš pradžių vėl įrašomi sekančio studento duomenys.  
Jei atsakoma ne (n), sekantis studentas nepridedamas ir programa toliau daro, ką darė Versija 0.1.  
### Versija 0.2  
Atsakius į pirmą klausimą "n", programa nuskaito duomenis iš failo "kursiokai.txt".   
Faile yra studento vardas, pavardė, namų darbų pažymiai ir egzamino balas.  
Programa viską nuskaito ir iškart apskaičiuoja galutini balą su mediana ir su vidurkiu.  
Toliau programa išveda studento vardą, pavardę ir galutini balą su vidurkiu ir su mediana.   
# Versija-0.3  
Tai yra Versija0.2 isskirstyta papildomai i funkcija.cpp ir funkcijos.h failus.  
funkcijos.h faile yra aprasytos funkcijos, kurios yra funkcija.cpp faile, taip pat aprašytos naudojamos bibliotekos.  
funkcija.cpp faile yra visos funkcijos.  
mainv3.cpp faile yra int main() funkcija.  
### Paleidimas: 
g++ -o test test5.cpp funkcija.cpp  
./test  
# Versija-0.4  
Versija-0.4 turi papildomą funkciją - sugeneruoti studentų failus, juos nuskaityti, ir suskaičiavus galutinį balą su vidurkiu išskirstyti studentus į du atskirus failus: "Galvotukus.txt" ir "Vargsiukus.txt".  
Norint paleisti naują funkciją, į patį pirmą klausimą  "Ar norite patys irasyti duomenis (t), ar norite, kad jie butu paimti is failo (n), ar kad duomenu failai butu sugeneruoti? (k): " reikia atsakyti "k".  
Tuo met klausiama vartotojo kiek jis norėtų sugeneruoti failų, įvedamas skaičius turi priklausyti intervalui [1;5].  
Tada vartotojas įveda pirmo failo studentų skaičių ir namų darbų skaičių.  
Tada programa išveda kiek užtruko sukurti šį studentų failą, kiek užtruko sukurto failo nuskaitymas, kiek užtruko studentų rūšiavimas į "Galvotukus" ir "Vargsiukus" ir kiek užtruko studentų duomenų išvedimas į "Galvotukus.txt" ir "Vargsiukus.txt".  
### Paleidimas:
g++ -o test mainv4.cpp funkcijos4.cpp  
./test  
# Versija-0.5  
Versija 0.5 yra versijos 0.4 patobulinimas, kad veiktų programa su skirtingais konteineriais - vector, list ir deque.  
Vartotojas, paleidęs programą, turi pasirinkti, kurį konteinerį naudos (vector - 1, list - 2, deque - 3).  
## Spartos Analizė  
Buvo tikrinama sparta su trim skirtingais konteineriais - vector, list ir deque.  
Tikrinimui buvo naudojami tie patys 5 failai: 100 studentų, 1000 studentų, 10000 studentų, 100000 studentų, 1000000 studentų (visi failai turėjo 9 namų darbus).   
### Kompiuterio parametrai:  
CPU - intel core i7  
RAM - 16GB  
HDD - 469 GB  
HDD - 469 GB    
## Duomenų nuskaitymas    
![image](https://user-images.githubusercontent.com/79039786/115520727-20da4600-a293-11eb-88f5-a1b8c0bc56f5.png)  
## Duomenų išvedimas  
![image](https://user-images.githubusercontent.com/79039786/115520656-0c964900-a293-11eb-9866-c99296bed45a.png)  
# Išvados  
List konteineris greičiausiai nuskaito duomenis iš failo ir išveda duomenis į "Vargašiukų" ir "Galvočių" failus. Antras, deque konteineris, o lėčiausiai veiksmus atlieka vector konteineris.
List konteineris greičiausiai nuskaito duomenis iš failo ir išveda duomenis į "Vargašiukų" ir "Galvočių" failus. Antras, deque konteineris, o lėčiausiai veiksmus atlieka vector konteineris.  
# Versija-1.0  
Versija-1.0 - Versijos.0.5 patobulinimas.   
Buvo pridėtos dvi strategijos studentų grupavimui į "Vargšiukus" ir "Galvotukus".    
Strategija 1: Bendro studentai konteinerio skaidymas į du naujus konteinerius "V" ir "G".  
Strategija 2: Bendro studentai konteinerio skaidymas į vieną naują konteinerį "V" ir tų duomenų ištrinimas iš bendro studentai konteinerio.  
## Spartos Analizė  
Su šiomis strategijomis bei strategija, kuri buvo naudojama praeitose versijose buvo testuojama programos sparta sugrupuoti studentus. 
Naudojami buvo tie patys 5 failai kaip versijoje 0.5. 
Spartos analizė buvo daroma su vector, list ir deque konteineriais.    
### Strategija 1  
![image](https://user-images.githubusercontent.com/79039786/117584057-48466500-b113-11eb-97ac-8c8f798c4c3f.png)  
### Strategija 2  
![image](https://user-images.githubusercontent.com/79039786/117584153-e76b5c80-b113-11eb-9cd6-64a2574c5197.png)  
### Strategija 3  
![image](https://user-images.githubusercontent.com/79039786/117584161-f6520f00-b113-11eb-98fc-d952d749f075.png)



