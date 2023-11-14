# Pirma užduotis (v0.2)
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
 - Failo turinys surūšiuojamas pagal minėtą kriterijų 
 - 