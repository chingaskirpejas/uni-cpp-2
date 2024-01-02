# Pirma užduotis (v1.2)
1. Šioje programoje naudojami duomenys susije su studentais - _vardas, pavarde, pažymiai, egzamino įvertinimas_
2. Vartotojas turi keturias parinktis darbui su duomenimis:
 	- Duomenų įvedimas ranka
  	- Duomenų automatinis generavimas (nerašant į failą)
  	- Duomenų nuskaitymas iš failo
  	- Failų su duomenimis generavimas
3. Duomenų išvedimo į ekraną metu bus rodomi studento vardas, **pavardė bei galutinis rezultatas**, _jei vartotojas pasirenka duomenų įvedimą ranka turėtų būt papildomai nurodoma pagal kokius kriterijus išvesti duomenis (**vidurkis** arba **mediana**)_

## Programos veikimo analizė
Programos veikimas buvo analizuojamas penkiais skirtingais failų dydžiais (failo pavadinime nurodytas studentų skaičius faile).<br>
```
1000.txt
10000.txt
100000.txt
1000000.txt
10000000.txt
```
<br>
Konkrečiai buvo analizuojamas failų su duomenimis generavimas, sugeneruotų duomenų nuskaitymas, rūšiavimas ir galiausiai surašymas į išvesties failus. <br>
<br>
Rūšiavimas atliekamas pagal studento galutini rezultatą kuris yra apskaičiuojamas pagal formulę (0.4 * Namų darbų vidurkis + 0.6 * Egzamino pažymys). Studentai turintys <br>
<br>

 **Analizės eiga**
 <br>
 Su kiekvienu iš nurodytų failų dydžių atliekami šie veiksmai paeiliui:
 - Sukuriamas ir užpildomas failas
 - Nuskaitomas failo turinys
 - Failo turinys surūšiuojamas pagal minėtą kriterijų trimis skirtingais budais
 - Visi rūšiavimo ir nuskaitymo rezultatai išvedami į ekraną

### Analizės išvados
Vector konteinerio atveju 
<br>
|                                               |  1000   |  10000  | 100000 | 1000000 | 10000000  |
| --------------------------------------------- |:-------:|:-------:|:------:|:-------:|:---------:|
|  Failo nuskaitymo laikas                      | 0,007 s | 0,040 s | 0,385 s | 4,289 s | 39,19 s  |
|  Failo išrūšiavimo laikas                     | 0 s     | 0,005 s | 0,021 s | 0,437 s | 5,135 s  |
|  Išrašymo į failus laikas                     | 0,009 s | 0,058 s | 0,525 s | 5,256 s | 53,7 s   |

|                      |  1 strategija | 2 strategija | 3 strategija |
| -------------------- |:-------------:|:------------:|:------------:|
| 1000                 | 0 s | 0 s | 0 s |
| 10000                | 0,002 s | 0,002 s | 0,002 s |
| 100000               | 0,029 s | 0,028 s | 0,022 s |
| 1000000              | 0,383 s | 0,215 s | 0,314 s |
| 10000000             | 27,580 s | 10,363 s | 33,330 s |


List konteinerio atveju <br>

|                                               |  1000   |  10000  | 100000 | 1000000 | 10000000  |
| --------------------------------------------- |:-------:|:-------:|:------:|:-------:|:---------:|
|  Failo nuskaitymo laikas                      | 0,007 s | 0,039 s | 0,391 s | 4,108 s | 43,785 s |
|  Failo išrūšiavimo vidutinis laikas           | 0 s     | 0,003 s | 0,036 s | 0,395 s | 9,195 s  |
|  Išrašymo į failus laikas                     | 0,008 s | 0,05 s  | 0,52 s  | 5,261 s | 55,987 s |

|                      |  1 strategija | 2 strategija | 3 strategija |
| -------------------- |:-------------:|:------------:|:------------:|
| 1000                 | 0,002 s | 0,001 s | 0 s |
| 10000                | 0,005 s | 0,005 s | 0,005 s |
| 100000               | 0,093 s | 0,097 s | 0,084 s |
| 1000000              | 0,595 s | 0,548 s | 0,234 s |
| 10000000             | 54,186 s | 37,327 s | 23,970 s |
<br>
<br>
### Analizės rezultatai

Pagal turimus duomenis matome, jog /*Vector*/ konteinerio atveju **antra** strategija yra efektyvesne su didesniais duomenų kiekiais. Taip pat matome jog /*List*/ konteinerio atveju, efektyviausia strategija yra **trečia**.


### Flagu testavimas

| Testuojamas failas   | o1 Vector | o1 List | o2 Vector | o2 List | o3 Vector | o3 List |
|-----------------------|-----------|---------|-----------|---------|-----------|---------|
| 100000.txt            | 9 ms      | 8 ms    | 9 ms      | 9 ms    | 9 ms      | 8 ms    |
| 1000000.txt           | 99 ms     | 95 ms   | 138 ms    | 93 ms   | 99 ms     | 93 ms   |


## Kompiuterio specifikacijos
CPU: Intel Core i5-6500 @ 3.2GHz<br>
GPU: Nvidia GTX 1060 3GB<br>
RAM: 8gb<br>
Atmintis: SSD<br>
