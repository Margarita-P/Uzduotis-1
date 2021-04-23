# Versija-0.2

Tai Versijos 0.1 papildymas.  
Atsakius į klausimą "Ar norite patys įvesti patys įvesti studento duomenis(t), ar norite, kad jie būtų nuskaityti iš failo (n)?: " t, programa darys viską ką daro Versija 0.1 ir dar galima papildomai pasirinkti ar iškart žinoma kiek bus studentų, ar ne.  
Jei atsakoma taip (t), reikia įrašyti kiek bus studentų, ir tiek studentų duomenų įvesti.  
Jei atsakoma ne (n), gale kiekvieno studento duomenų įrašymo reikia atsakyti į klausimą "Ar norite pridėti dar vieną studentą? "  
Jei atsakoma taip (t), iš pradžių vėl įrašomi sekančio studento duomenys.  
Jei atsakoma ne (n), sekantis studentas nepridedamas ir programa toliau daro, ką darė Versija 0.1.  
## Versija 0.2  
Atsakius į pirmą klausimą "n", programa nuskaito duomenis iš failo "kursiokai.txt".   
Faile yra studento vardas, pavardė, namų darbų pažymiai ir egzamino balas.  
Programa viską nuskaito ir iškart apskaičiuoja galutini balą su mediana ir su vidurkiu.  
Toliau programa išveda studento vardą, pavardę ir galutini balą su vidurkiu ir su mediana.  
# Versija-0.5  
Versija 0.5 yra versijos 0.4 patobulinimas, kad veiktų programa su skirtingais konteineriais - vector, list ir deque.  
Vartotojas, paleidęs programą, turi pasirinkti, kurį konteinerį naudos (vector - 1, list - 2, deque - 3).  
## Spartos Analizė  
Buvo tikrinama sparta su trim skirtingais konteineriais - vector, list ir deque.  
Tikrinimui buvo naudojami tie patys į failai: 100 studentų, 1000 studentų, 10000 studentų, 100000 studentų, 1000000 studentų (visi failai turėjo 9 namų darbus).   
### Kompiuterio parametrai:  
CPU - intel core i7  
RAM - 16GB  
HDD - 469 GB  
  
## Duomenų nuskaitymas    
![image](https://user-images.githubusercontent.com/79039786/115520727-20da4600-a293-11eb-88f5-a1b8c0bc56f5.png)  
## Duomenų išvedimas  
![image](https://user-images.githubusercontent.com/79039786/115520656-0c964900-a293-11eb-9866-c99296bed45a.png)  
# Išvados  
List konteineris greičiausiai nuskaito duomenis iš failo ir išveda duomenis į "Vargašiukų" ir "Galvočių" failus. Antras, deque konteineris, o lėčiausiai veiksmus atlieka vector konteineris.

